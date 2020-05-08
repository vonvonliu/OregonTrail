#include "Probability.h"
#include <iostream>
#include <string>
using namespace std;

Probability::Probability(){
    srand(time(0));
    randomNum = 0;
    canHunt = true;
}

int Probability::randomNumbers(int min, int max){
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

bool Probability::puzzle(){
    int answer = 0;
    string guess = "";
    // need to write before calling rand() to seed the random number generator
    answer = randomNumbers(1, 10); // random numbers between 1 and 10
    for(int i = 0; i < 3; i++){
        cout << "What is your guess?" << endl;
        getline(cin, guess);
        if(stoi(guess) == answer){
            cout << "You guessed correctly." << endl;
            return true;
        }else
            cout << "Your guess is incorrect." << endl;
    }
    return false;
}

int Probability::huntRabbit(int bullets){
    int encounter = 0;
    bool successful = false;
    string choice = "";
    
    if(bullets < 10){
        cout << "Unfortunately, you do not have enough bullets to hunt." << endl;
        return -1;
     }
     
    encounter = randomNumbers(1, 100);
    if(encounter >= 50){
        cout << "Sorry, you did not encounter a rabbit." << endl;
        return 0;
    }
    cout << "You got lucky! You encountered a rabbit. Would you like to hunt? (Y/N)" << endl;
    getline(cin, choice); //gets the input from user
    while(choice != "Y" && choice != "y" && choice != "n" && choice != "N"){
         cout << "Please enter a valid choice." << endl;
         getline(cin, choice); //gets the input from user
     }
     if(choice == "N" || choice == "n")
        return 0;
     else if(choice == "Y" || choice == "y"){
        cout << "In order to see if you get the rabbit, you need to solve a puzzle. You have three tries to guess a number." << endl;
        successful = puzzle();
        if(!successful){
            cout << "Sorry. You had an unsucessful hunt for the rabbit." << endl;
            return 0;
        }
     cout << "Nice! You got the rabbit!" << endl;
     return 2;
     }
}

int Probability::huntFox(int bullets){
    int encounter = 0;
    bool successful = false;
    string choice = "";

    if(bullets < 10){
        cout << "Unfortunately, you do not have enough bullets to hunt." << endl;
        return -1;
     }
     
    encounter = randomNumbers(1, 100);
    if(encounter >= 25){
        cout << "Sorry, you did not encounter a fox." << endl;
        return 0;
    }
    cout << "You got lucky! You encountered a fox. Would you like to hunt? (Y/N)" << endl;
    getline(cin, choice); //gets the input from user
    while(choice != "Y" && choice != "y" && choice != "n" && choice != "N"){
         cout << "Please enter a valid choice." << endl;
         getline(cin, choice); //gets the input from user
     }
     if(choice == "N" || choice == "n")
        return 0;
     else if(choice == "Y" || choice == "y"){
        cout << "In order to see if you get the fox, you need to solve a puzzle. You have three tries to guess a number." << endl;
        successful = puzzle();
        if(!successful){
            cout << "Sorry. You had an unsucessful hunt for the fox." << endl;
            return 0;
        }
        cout << "Nice! You got the fox!" << endl;
        return 5;
     }
}

int Probability::huntDeer(int bullets){
    int encounter = 0;
    bool successful = false;
    string choice = "";

    if(bullets < 10){
        cout << "Unfortunately, you do not have enough bullets to hunt." << endl;
        return -1;
     }
     
    encounter = randomNumbers(1, 100);
    if(encounter >=15){
        cout << "Sorry, you did not encounter a deer." << endl;
        return 0;
    }
    cout << "You got lucky! You encountered a deer. Would you like to hunt? (Y/N)" << endl;
    getline(cin, choice); //gets the input from user
    while(choice != "Y" && choice != "y" && choice != "n" && choice != "N"){
         cout << "Please enter a valid choice." << endl;
         getline(cin, choice); //gets the input from user
     }
     if(choice == "N" || choice == "n")
        return 0;
     else if(choice == "Y" || choice == "y"){
        cout << "In order to see if you get the deer, you need to solve a puzzle. You have three tries to guess a number." << endl;
        successful = puzzle();
        if(!successful){
            cout << "Sorry. You had an unsucessful hunt for the deer." << endl;
            return 0;
        }
        cout << "Nice! You got the deer!" << endl;
        return 5;
     }
}

int Probability::huntBear(int bullets){
    int encounter = 0;
    bool successful = false;
    string choice = "";

    if(bullets < 10){
        cout << "Unfortunately, you do not have enough bullets to hunt." << endl;
        return -1;
     }
     
    encounter = randomNumbers(1, 100);
    if(encounter >= 7){
        cout << "Sorry, you did not encounter a bear." << endl;
        return 0;
    }
    cout << "You got lucky! You encountered a bear. Would you like to hunt? (Y/N)" << endl;
    getline(cin, choice); //gets the input from user
    while(choice != "Y" && choice != "y" && choice != "n" && choice != "N"){
         cout << "Please enter a valid choice." << endl;
         getline(cin, choice); //gets the input from user
     }
     if(choice == "N" || choice == "n")
        return 0;
     else if(choice == "Y" || choice == "y"){
        cout << "In order to see if you get the bear, you need to solve a puzzle. You have three tries to guess a number." << endl;
        successful = puzzle();
        if(!successful){
            cout << "Sorry. You had an unsucessful hunt for the bear." << endl;
            return 0;
        }
        cout << "Nice! You got the bear!" << endl;
        return 5;
     }
}

int Probability::huntMoose(int bullets){
    int encounter = 0;
    bool successful = false;
    string choice = "";
    
    if(bullets < 10){
        cout << "Unfortunately, you do not have enough bullets to hunt." << endl;
        return -1;
     }
     
    encounter = randomNumbers(1, 100);
    if(encounter >= 5){
        cout << "Sorry, you did not encounter a moose." << endl;
        return 0;
    }
    cout << "You got lucky! You encountered a moose. Would you like to hunt? (Y/N)" << endl;
    getline(cin, choice); //gets the input from user
    while(choice != "Y" && choice != "y" && choice != "n" && choice != "N"){
         cout << "Please enter a valid choice." << endl;
         getline(cin, choice); //gets the input from user
     }
     if(choice == "N" || choice == "n")
        return 0;
     else if(choice == "Y" || choice == "y"){
        cout << "In order to see if you get the moose, you need to solve a puzzle. You have three tries to guess a number." << endl;
        successful = puzzle();
        if(!successful){
            cout << "Sorry. You had an unsucessful hunt for the moose." << endl;
            return 0;
        }
        cout << "Nice! You got the moose!" << endl;
        return 5;
     }
}