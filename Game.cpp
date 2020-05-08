#include "Game.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

Game::Game(){
    srand(time(0));
    player = Player(); //player object
    store = Store(); //store object
    inventory = Inventory();
    journey = Journey();
    probability = Probability();
    bill = 0;
    mileStoneIndex = 0;
}

/*
checkChoiceSize: takes a string that repreents the choice of the user
                 returns the length of the string to check if the choice is valid
*/
int Game::checkChocieSize(string input){
  int choiceSize = 0; //this portion checks that the input of the player is valid before using stoi
  for(int i = 0; i < input.length(); i++) //loops thorugh the choice and totals up the length of the characters
      choiceSize += input[i];
  return choiceSize;
}

Player Game::getPlayer(){
    return player; //returns the player
}

Store Game::getStore(){
    return store; //returns the store
}

Inventory Game::getInventory(){
    return inventory;
}

Journey Game::getJourney(){
    return journey;
}

int Game::randomNumbers(int min, int max){
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

/*
displayIntroInfo: displays the introduction information to the user
*/
void Game::displayIntroInfo(){
     cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM" << endl; //informs player about objective of game
     cout << "INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847. " << endl;
     cout << "YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL" << endl;
     cout << "IN 5-6 MONTHS --- IF YOU MAKE IT ALIVE." << endl << endl;
}

/*
setPlayer: prompts the user for his/her name then asks for the four companions' names then sets the names of the players using the player array,
            checks if the names are repeating andnot empty
*/
void Game::setPlayer(){
    cout << "Please enter your name: " << endl; //prompts user for name
     string playerName = ""; //saves the player name from user
     getline(cin, playerName); //retrieves name from user input
     while(playerName.length() == 0){ //checks to make sure the name is not a space or empty
         cout <<"Please enter a valid name." << endl;
         getline(cin, playerName); //gets the name again
     }
        
     player.setName(playerName, 0); //sets the name of the first player
     cout << "Please enter the names of your four companions:" << endl; //prompts for the four other player names
     
     for(int i = 1; i < 5; i++){ //counts until four players
        cout << i << ". ";
        getline(cin, playerName); //gets the next name
        
        bool repeatName = false; //true if there is a reapting name, false if not
        for(int j = 0; j < 5; j++){ //checks for no repeating names
            if(playerName == player.getName(j) || playerName.length() == 0){ //if same name or nothing entered
                if(playerName == player.getName(j)){
                    cout << "Please enter a different name from player " << j << "." << endl;
                    repeatName = true;
                    break;
                }else{
                    cout << "Please enter a name." << endl; //if nothing entered
                    repeatName = true;
                    break;
                }
            }
        }
        
        if(!repeatName)
            player.setName(playerName, i); //sets the name of each player
        else
            i--; //decrement i to ask again for the same name
     }
}

/*
displayInitialConditions function: this function displays initial conditions of the game to the user
*/
void Game::displayInitialConditions(){
    //This section informs the player about his/her intitial conditions
     cout << "\nYou are starting at Independence, Missouri. You must travel 2,040 miles to Oregon City" << endl;
     cout << "You've saved up $1200 for this long journey. However, you've spent $200 on buying a wagon." << endl;
     cout << "Thus, you have $1000 left for this trip." << endl;
     cout << "\nBefore you leave, you have the opportunity of visiting the store. Would you like to do so? (y/n)" << endl;
}

/*
willVisitStore function: returns a boolean
                        asks if the player wants to visit the store and if so, inform the player about needed items
*/
bool Game::willVisitStore(){
     string choice; //saves the input from user
     getline(cin, choice); //gets the input from user
     while(choice != "Y" && choice != "y" && choice != "n" && choice != "N"){
         cout << "Please enter a valid choice." << endl;
         getline(cin, choice); //gets the input from user
     }
     if(choice == "Y" || choice == "y"){ //if the user says yes
        cout << "Welcome to the Store! We have:\n\n- OXEN- YOU CAN SPEND $100-$200 ON YOUR TEAM. "; //informs the user about store
        cout << "THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS." << endl;
        cout << "- FOOD- THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK." << endl;
        cout << "- BULLETS - $2 BUYS A BOX OF 20 BULLETS. YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS AND FOR HUNTING FOOD" << endl;
        cout << "- MISCELLANEOUS SUPPLIES- THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS" << endl;
        cout << "\nYOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW." << endl;
        cout << "HOWEVER, ITEMS COST INCREASINGLY HIGHER AT EACH OF THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD.\n" << endl;
        
        return true;
     }else
         return false;
}

/*
updateBill: takes in the current bill, and the amount to be added and returns the updated bill
            prints out the curernt bill then adds
*/

double Game::updateBill(double currentBill, double addition){
    double newBill = currentBill + addition;
    cout << "Current bill: $" << newBill << endl;
    return newBill;
}

/*
setOxen: takes in the current total money spent on buying oxen and returns the total amount spent on oxen for this round, -1 if this round will deplete money
        checks if on the first turn, the money spent on oxen is between 100 and 200 inclusive while the current toal is still 0 or if the current total
        plus the price of yokes desired is greater than 200, and if so, then prompt for another entry and tells user
        if not, then update inventory then reutrns the round total
*/
double Game::setOxen(double currentTotal, double currMon){
    string numYoke; //saves the user input
    
    cout << "You must spend at least $100 and no more than $200 dollars on oxen. How many yokes would you like? (2 oxen per yoke)" << endl;
    getline(cin, numYoke); //gets user input
    
    int yoke = stoi(numYoke); //stores the input as an int
    double price = yoke*store.getPrice(0); //save the price of the total of yokes
    
    if(currMon + price > 1000){
        cout << "You do not have enough money to buy this much oxen." << endl;
        return -1;
    }
    
    while(((price > 200 || price < 100) && (currentTotal == 0)) || (price + currentTotal > 200)){ //while it's within the range and have not bought before
        if(price > 200 && currentTotal == 0) //if not bought and greater than 200
            cout << "That is too many yokes. Please enter a lower number." << endl;
        else if(price < 100 && currentTotal == 0) //if not bought and less than 100
            cout << "That is too few yokes. Please enter a higher number." << endl;
        else if(price + currentTotal > 200) //if total spent is too much
            cout << "That is too many yokes combined with the previous yokes you've purchased. Please enter a lower number" << endl;
        getline(cin,numYoke); //gets input again and stores again then recalculates price
        yoke = stoi(numYoke);
        price = yoke*store.getPrice(0);
    }
        inventory.modifyInventory(0, yoke*2); //update the inventory for oxen

        return price; //reutrn total
}

/*
setCurrent: takes in the current total money spent on buying food and returns the total pounds of food, returns -1 if this round will depelete money
        checks if on the first turn, the the total pounds is greater than 2000 while current total is still 0 or if the current total
        plus the price of this round is greater than 2000, then tell the user so
        if not, then update inventory then reutrns the round total
*/
int Game::setFood(int currentTotal, double currMon){
    string numPounds;
    
    cout << "You should spend about 200lb of food per person. However, you cannot exceed 1000lb total since your wagon cannot carry more than this much food.\nHow many pounds would you like?" << endl;
    getline(cin, numPounds); //gets user input
    
    int pounds = stoi(numPounds); //stores the input as an int
    //double price = pounds*store.getPrice(1); //saves the price of the total pounds of food
    
    if(currMon + pounds*store.getPrice(1) > 1000){
        cout << "You do not have enough money to buy this much food." << endl;
        return -1;
    }
    
    while(((pounds > 1000) && (currentTotal == 0)) || (pounds + currentTotal > 1000)){ //while it's within the range and have not bought before
        if(pounds > 1000 && currentTotal == 0) //if not bought and greater than 200
            cout << "That is too many pounds. Please enter a lower number." << endl;
        else if(pounds + currentTotal > 1000) //if total spent is too much
            cout << "That is too many pounds combined with the previous pounds you've purchased. Please enter a lower number" << endl;
        getline(cin,numPounds); //gets input again and stores again then recalculates price
        pounds = stoi(numPounds);
    }
        inventory.modifyInventory(1, pounds); //update the inventory for food
        return pounds; //reutrn total
}

int Game::setBullets(int currentTotal, double currMon){
    string numBox;
    
    cout << "You can use bullets to hunt for food and there are 20 bullets in one box. How many boxes would you like?" << endl;
    getline(cin, numBox); //gets user input
    
    int boxes = stoi(numBox); //stores the input as an int
    double price = boxes*store.getPrice(2); //saves the price of the total pounds of food
    
    if(currMon + price > 1000){
        cout << "You do not have enough money to buy this much bullets." << endl;
        return -1;
    }
    inventory.modifyInventory(2, boxes*20); //update the inventory for food
    return boxes; //reutrn total
}

int Game::setWagon(int currentTotal, double currMon){
    string numParts;
    
    cout << "You will need wagon parts to repair your wagon. Wagon parts consist of: wheels, axles, tongues. How many parts would you like?" << endl;
    getline(cin, numParts); //gets user input
    
    int parts = stoi(numParts); //stores the input as an int
    double price = parts*store.getPrice(3); //saves the price of the total parts
    
    if(currMon + price > 1000){
        cout << "You do not have enough money to buy this many parts." << endl;
        return -1;
    }
    inventory.modifyInventory(3, parts); //update the inventory for parts
    return parts; //reutrn total
}

int Game::setMed(int currentTotal, double currMon){
    string numKits;
    
    cout << "You will need medical kits for health problems and emergencies. How many kits would you like?" << endl;
    getline(cin, numKits); //gets user input
    
    int kits = stoi(numKits); //stores the input as an int
    double price = kits*store.getPrice(4); //saves the price of the kits
    
    if(currMon + price > 1000){
        cout << "You do not have enough money to buy this many kits." << endl;
        return -1;
    }
    inventory.modifyInventory(4, kits); //update the inventory for parts
    return kits; //reutrn total
}

void Game::setMoneyAfterStore(double amount){
    inventory.modifyMoney(amount);
}

void Game::askForDate(){
    cout << "Would you like to: 1. start at the default date or 2. choose you own date (between March 1st to May 1st)" << endl;
    string choice = "";
    getline(cin, choice);
    while(choice != "1" && choice != "2"){
        cout <<"Please enter a valid choice" << endl;
        getline(cin, choice);
    }
    if(choice == "1"){
        journey.setDay(28);
        journey.setMonth(3);
    }
    if(choice == "2"){
        cout << "Enter the desired month: ";
        getline(cin, choice);
        int month = stoi(choice);
        while(month <3 || month > 5 ){
            cout << "Please enter a valid month" << endl;
            getline(cin, choice);
            month = stoi(choice);
        }
        journey.setMonth(stoi(choice));
        cout << "Enter the desired day: ";
        getline(cin, choice);
        int day = stoi(choice);
        cout << "day: " << day << endl;
        while(day > 31 || day < 1 ){
            cout << "Please enter a valid day" << endl;
            getline(cin, choice);
            day = stoi(choice);
        }
        journey.setDay(stoi(choice));
    }
}

void Game::statusUpdate(){
    cout << "\n<<--------------------Current Status-------------------->>" << endl;
    cout << "Date: " << journey.getMonthNames(journey.getMonth()) << " " << journey.getDay() << ", " << journey.getYear() << endl;
    cout << "Miles Traveled: " << journey.getMiles() << endl;
    cout << "Distance to the next milestone: " << journey.getDist(mileStoneIndex) - journey.getMiles() << " miles" << endl;
    cout << "Food: " << inventory.getQuantity(1)  << "lbs" << endl;
    cout << "Bullets: " << inventory.getQuantity(2) << endl;
    cout << "Cash: $" << inventory.getMoney() << endl;
    //next fort
}

void Game::displayTurnChoices(){
    cout << "\n***What would you like to do?***" << endl;
    cout << "1. Stop to rest" << endl;
    cout << "2. Continue on trail" << endl;
    cout << "3. Hunt" << endl;
    cout << "4. Quit" << endl;
}

void Game::getSick(){
    int theIll = randomNumbers(0, 4);
    int sickness = randomNumbers(1, 6);
    
    if(sickness == 1){
        cout << "Oh no! " << player.getName(theIll) << " has typhoid!" << endl;
    }else if(sickness == 2){
        cout << "Oh no! " << player.getName(theIll) << " has cholera!" << endl;
    }else if(sickness == 3){
        cout << "Oh no! " << player.getName(theIll) << " has diarrhea!" << endl;
    }else if(sickness == 4){
        cout << "Oh no! " << player.getName(theIll) << " has measles!" << endl;
    }else if(sickness == 5){
        cout << "Oh no! " <<player.getName(theIll) << " has dysentery!" << endl;
    }else{
        cout << "Oh no! " << player.getName(theIll) << " has a fever!" << endl;
    }
    
    if(inventory.getQuantity(4) > 0){
        int death = randomNumbers(1, 100);
        if(death > 50){
            cout << "Sorry. " << player.getName(theIll) << " has died although you tried to save them." << endl;
            player.setAlive(false, theIll);
            return;
        }else{
            cout << "Fortunately, " << player.getName(theIll) << " survived!" << endl;
            return;
        }
    }else if(inventory.getQuantity(4) == 0){
        cout << "Do you want to: 1) Rest, or 2) Press On ?" << endl;
        string choice;
        getline(cin, choice);
        while(choice != "1" && choice != "2"){
         cout << "Please enter a valid choice." << endl;
         getline(cin, choice); //gets the input from user
        }
        if(choice == "1"){
            int mayDie = randomNumbers(1, 100);
            journey.updateDate(3);
            inventory.modifyInventory(1, -(3*5*3));
            if(mayDie > 30)
                cout << "Fortunately, " << player.getName(theIll) << " survived!" << endl;
            else{
                cout << "Sorry. " << player.getName(theIll) << " has died." << endl;
                player.setAlive(false, theIll);
                return;
            }
        }else{
            int mayDie = randomNumbers(1, 100);
            if(mayDie > 70)
                cout << "Fortunately, " << player.getName(theIll) << " survived!" << endl;
            else{
                cout << "Sorry. " << player.getName(theIll) << " has died." << endl;
                player.setAlive(false, theIll);
                return;
            }
            
        }
    }
}


void Game::oxenDies(){
    inventory.modifyInventory(0, -1);
    cout << "Oh no! One of your oxen has died! You have " << inventory.getQuantity(0) << " ox(en) left." << endl;
}

bool Game::wagonBroke(){
    if(inventory.getQuantity(0) > 0){
        inventory.modifyInventory(0, -1);
        return false;
    }else
        return true;
}

bool Game::calcMisfortune(){
    int misfortune = 0;
    misfortune = randomNumbers(1, 100);
    if(misfortune > 40)
        return false;
    return true;
}

bool Game::determineMisfortune(){
    int typeMisfor = 0;
    typeMisfor = randomNumbers(1, 4);
    if(typeMisfor == 1){
        getSick();
    }else if(typeMisfor == 2){
        oxenDies();
    }else if(typeMisfor == 3){
        return wagonBroke();
    }else{
        cout << "Wow! You found a treasure chest of 500 dollars, 2 oxen, 50 bullets, 1 wagon part, 50 pounds of food, a a medical kit!" << endl;
        inventory.modifyMoney(500);
        inventory.modifyInventory(0, 2);
        inventory.modifyInventory(1, 50);
        inventory.modifyInventory(2, 50);
        inventory.modifyInventory(3, 1);
        inventory.modifyInventory(4, 1);
    }
    return false;
}

void Game::raiderAttack(){
    double probRaided = ((((pow((journey.getMiles() / 100) - 4, 2) + 72) / (pow((journey.getMiles() / 100) - 4, 2) + 12)) - 1) * 1000);
    //double probRaided = ((((journey.getMiles()/100 − 4) * (journey.getMiles()/100 - 4) + 72) / ((journey.getMiles()/100 − 4) * (journey.getMiles()/100 - 4) + 12) ) - 1) * 1000;
    bool raided = randomNumbers(1, 1000) <= probRaided;
    if(raided){
        cout << "RAIDERS AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << "Do you want to 1) Run or 2) Attack or 3) Surrender ?" << endl;
        string choice;
        getline(cin, choice);
        while(choice != "1" && choice != "2" && choice != "3"){
         cout << "Please enter a valid choice." << endl;
         getline(cin, choice); //gets the input from user
        }
        if(choice == "1"){
            cout << "You survived! But, in the hurry to flee the raiders, you left behind 1 ox, 10 lbs. of food and 1 wagon part." << endl;
            inventory.modifyInventory(0, -1);
            inventory.modifyInventory(1, -10);
            inventory.modifyInventory(3, -1);
        }else if(choice == "2"){
            cout << "In order to win the battle against these raiders, you must guess a number correctly (1 to 10)" << endl;
            if(probability.puzzle()){
                cout << "Great job! You won and gained 50 lbs of food and 50 bullets!" << endl;
                inventory.modifyInventory(1, 50);
                inventory.modifyInventory(2, 50);
            }else{
                cout << "Sorry. You lost 50 bullets and a quarter of your cash reserves to them." << endl;
                inventory.modifyInventory(2, -50);
                inventory.modifyMoney(-(inventory.getMoney()*0.25));
            }
        }else{
            cout << "You surrendered but lost a quarter of your cash reserves." << endl;
            inventory.modifyMoney(-(inventory.getMoney()*0.25));
        }
        if(inventory.getQuantity(1) > 1000)
            inventory.setInventory(1, 1000);
    }
}

void Game::rest(){
    int numRestDays = 0; //saves the number of rest days
    // need to write before calling rand() to seed the random number generator
    
    numRestDays = randomNumbers(1,3); // random numbers between 1 and 3
    
    journey.updateDate(numRestDays); //update the date
    cout << "You have rested " << numRestDays << " day(s)." << endl; //informs the user how long they rested
    inventory.modifyInventory(1, -((3*5)*numRestDays)); //update the food
}


bool Game::continueTrail(){
    inventory.modifyInventory(1, -(3*5*14));
    journey.updateDate(14);
    int distanceTrav = randomNumbers(70, 140);
    //cout << journey.getDist(mileStoneIndex) << endl;
    if(distanceTrav+journey.getMiles() <= journey.getDist(mileStoneIndex)){
        journey.modifyMiles(distanceTrav);
    }else if(distanceTrav+journey.getMiles() >= journey.getDist(mileStoneIndex)){
        for(int i = 0; i < 4; i++){
            if(journey.getFortDist(i) == journey.getDist(mileStoneIndex)){
                cout << "You have reached " << journey.getFortName(i) << endl;
                reachFort(i);
            }else if(journey.getRivDist(i) == journey.getDist(mileStoneIndex)){
                cout << "You have reached " << journey.getRiverName(i) << endl;
                return reachRiver(i);
            }
        
        }
        if(journey.getFortDist(4) == journey.getDist(mileStoneIndex)){
            cout << "You have reached " << journey.getFortName(4) << endl;
            reachFort(4);
        }else if(journey.getFortDist(5) == journey.getDist(mileStoneIndex)){
            cout << "You have reached " << journey.getFortName(5) << endl;
            reachFort(5);
        }
        
        journey.modifyMiles(journey.getDist(mileStoneIndex));
        mileStoneIndex++;
    }
}

void Game::hunt(){
    journey.updateDate(1);
    int rabbit = probability.huntRabbit(inventory.getQuantity(2));
    int fox = -3;
    int deer = -3;
    int bear = -3;
    int moose = -3;
    
    if(rabbit > 0){
        inventory.modifyInventory(1, 2);
        inventory.modifyInventory(2, -10);
        fox = probability.huntFox(inventory.getQuantity(2));
    }else if(rabbit == 0){
        fox = probability.huntFox(inventory.getQuantity(2));
    }else if(rabbit == -1){
        return;
    }
    
    if(fox > 0){
        inventory.modifyInventory(1, 5);
        inventory.modifyInventory(2, -8);
        deer = probability.huntDeer(inventory.getQuantity(2));
    }else if(fox == 0){
        deer = probability.huntDeer(inventory.getQuantity(2));
    }else if(fox == -1){
        return;
    }
    
    if(deer > 0){
        inventory.modifyInventory(1, randomNumbers(30, 55));
        inventory.modifyInventory(2, -5);
        bear = probability.huntBear(inventory.getQuantity(2));
    }else if(deer == 0){
        bear = probability.huntBear(inventory.getQuantity(2));
    }else if(deer == -1){
        return;
    }
    
    if(bear > 0){
        inventory.modifyInventory(1, randomNumbers(100, 350));
        inventory.modifyInventory(2, -10);
        moose = probability.huntMoose(inventory.getQuantity(2));
    }else if(bear == 0){
        moose = probability.huntMoose(inventory.getQuantity(2));
    }else if(bear == -1){
        return;
    }
    
    if(moose > 0){
        inventory.modifyInventory(1, randomNumbers(300, 600));
        inventory.modifyInventory(2, -12);
    }else if(moose == 0){
        
    }else if(moose == -1){
        return;
    }
    if(rabbit >= 0 || fox >= 0 || deer >= 0 || bear >= 0 || moose >= 0){
        cout << "How well do you want to eat after this hunting day?" << endl;
        cout << "(1)Poorly: 2 lbs of food, per person" << endl;
        cout << "(2)Moderately: 3 lbs of food, per person" << endl;
        cout << "(3)Well: 5 lbs of food, per person" << endl;
        string choice = "";
        getline(cin, choice);
        if(choice == "1")
            inventory.modifyInventory(1, -(2*5));
        if(choice == "2")
            inventory.modifyInventory(1, -(3*5));
        if(choice == "3")
            inventory.modifyInventory(1, -(5*5));
    }  
    if(inventory.getQuantity(1) > 1000){
        cout << "Although you acquired a lot of food during this hunting day, you were only able to carry some of it back since the wagon cannot carry more than 1000 lbs." << endl;
        inventory.setInventory(1, 1000);
    }
}

void Game::visitStore(){
    int currentTot = 0;
    string choice;
    bool done = false;
       while((choice != "6") && !done && inventory.getMoney() > 0){ //while the player doesn't wnat ot leave the store
            store.displayStore(); //display store items
           getline(cin, choice); //get the choice from the user
           
            while(checkChocieSize(choice) < 49 || checkChocieSize(choice) > 54 || choice.length() == 0){ //checks that the user input a number, not anything else
              cout << "Please enter a valid selection." << endl;
              getline(cin, choice); //get the choice from the user
            }

           switch(stoi(choice)){
               case 1:{
                   string numYokes;
    
                    cout << "How many bullets would you like?" << endl;
                    getline(cin, numYokes); //gets user input
    
                    int yokes = stoi(numYokes); //stores the input as an int
                    double price = yokes*store.getPrice(0); //saves the price of the kits
    
                    if(currentTot + price > inventory.getMoney()){
                        cout << "You do not have enough money to buy this many oxen." << endl;
                        break;
                    }
                    inventory.modifyInventory(0, yokes*2); //update the inventory for parts
                    inventory.modifyMoney(-price);
                   
                   cout << endl;
                    break;
                   
                   cout << endl;
                    break;
               }
               case 2:{
                   string numPounds;
    
                    cout << "How many bullets would you like?" << endl;
                    getline(cin, numPounds); //gets user input
    
                    int pounds = stoi(numPounds); //stores the input as an int
                    double price = pounds*store.getPrice(1); //saves the price of the kits
    
                    if(currentTot + price > inventory.getMoney()){
                        cout << "You do not have enough money to buy this much food." << endl;
                        break;
                    }
                    inventory.modifyInventory(1, pounds); //update the inventory for parts
                    inventory.modifyMoney(-price);
                   
                   cout << endl;
                    break;
               }
               case 3:{
                   string numBull;
    
                    cout << "How many bullets would you like?" << endl;
                    getline(cin, numBull); //gets user input
    
                    int bullets = stoi(numBull); //stores the input as an int
                    double price = bullets*store.getPrice(2); //saves the price of the kits
    
                    if(currentTot + price > inventory.getMoney()){
                        cout << "You do not have enough money to buy this many bullets." << endl;
                        break;
                    }
                    inventory.modifyInventory(2, bullets*20); //update the inventory for parts
                    inventory.modifyMoney(-price);
                   
                   cout << endl;
                    break;
               }
               case 4:{
                    string numParts;
    
                    cout << "How many parts would you like?" << endl;
                    getline(cin, numParts); //gets user input
    
                    int parts = stoi(numParts); //stores the input as an int
                    double price = parts*store.getPrice(3); //saves the price of the kits
    
                    if(currentTot + price > inventory.getMoney()){
                        cout << "You do not have enough money to buy this many parts." << endl;
                        break;
                    }
                    inventory.modifyInventory(3, parts); //update the inventory for parts
                    inventory.modifyMoney(-price);
                    cout << endl;
                    break;
               }   
                case 5:{
                    string numKits;
    
                    cout << "How many kits would you like?" << endl;
                    getline(cin, numKits); //gets user input
    
                    int kits = stoi(numKits); //stores the input as an int
                    double price = kits*store.getPrice(4); //saves the price of the kits
    
                    if(currentTot + price > inventory.getMoney()){
                        cout << "You do not have enough money to buy this many kits." << endl;
                        break;
                    }
                    inventory.modifyInventory(4, kits); //update the inventory for parts
                    inventory.modifyMoney(-price);
                    cout << endl;
                    break;
                }
                    
                case 6:
                    // quit 
                  //display total bill and inventory here
                  inventory.modifyMoney(currentTot);
                  //cout << "\n*****Let the journey begin!*****" << endl;
                  done = true;
                  cout << endl;
                  break;
           }
}
}

bool Game::reachRiver(int index){
    cout << "What do you want to do? 1) Rest or 2) Cross River" << endl;
    string choice;
    getline(cin, choice);
    while(choice != "1" && choice != "2"){
         cout << "Please enter a valid choice." << endl;
         getline(cin, choice); //gets the input from user
    }
    while(choice != "2"){
        journey.updateDate(1);
        inventory.modifyInventory(1, -(3*5));
        cout << "What do you want to do? 1) Rest or 2) Cross River" << endl;
        getline(cin, choice);
    }
    if(journey.getRivWid(index) > 3){
        cout << "You need a ferry to cross this river and it costs $10 per person." << endl;
        if(inventory.getMoney() < 50){
            cout << "You were unable to cross the river because you have no more money to spend." << endl;
            return false;
        }
        inventory.modifyMoney(-50);
    }
    cout << "You have successfully crossed the river" << endl;
    return true;
}

void Game::reachFort(int index){
    cout << "What do you want to do? 1) Rest or 2) Visit the store or 3) Continue on trail" << endl;
    string choice;
    getline(cin, choice);
    while(choice != "1" && choice != "2" && choice != "3"){
         cout << "Please enter a valid choice." << endl;
         getline(cin, choice); //gets the input from user
    }
    while(choice == "1" || choice == "2"){
        if(choice == "1"){
            journey.updateDate(1);
            inventory.modifyInventory(1, -(3*5));
            cout << "What do you want to do? 1) Rest or 2) Visit the store or 3) Continue on trail" << endl;
            getline(cin, choice);
        }
        if(choice == "2"){
            visitStore();
            cout << "What do you want to do? 1) Rest or 2) Visit the store or 3) Continue on trail" << endl;
            getline(cin, choice);
        }
    }
}

