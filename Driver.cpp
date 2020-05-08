// CSCI1300 Fall 2018
// Author: Yvonne Liu
// Recitation: 203 -Sebastian Laudenschlager
// Cloud9 Workspace Editor Link: https://c9.io/vonvonliu
// Final Project


#include <iostream>
#include <iomanip>
#include <string>
#include "Player.h"
#include "Store.h"
#include "Inventory.h"
#include "Game.h"
using namespace std;

 
 int main(){
     
    Game game = Game(); //create game obejct
    
    game.displayIntroInfo(); //display the intro information about this game
    game.setPlayer(); //get the player names and se tthe players
    game.displayInitialConditions(); //print out the initial conditions
    
    if(game.willVisitStore()){ //displays store and if the player wants to visit the store
       double currentTot = 0;
       double oxenTotal = 0;
       int foodTotal = 0;
       double bulletTotal = 0;
       double wagonTotal = 0;
       double medTotal = 0;
       bool displayedMenu = false;
       string choice = ""; //saves the choice of the user
       bool done = false;
       
      game.getStore().displayStore(); //display store items
       
       while((choice != "6") && !done){ //while the player doesn't wnat ot leave the store
           getline(cin, choice); //get the choice from the user
           
            while(game.checkChocieSize(choice) < 49 || game.checkChocieSize(choice) > 54 || choice.length() == 0){ //checks that the user input a number, not anything else
              cout << "Please enter a valid selection." << endl;
              getline(cin, choice); //get the choice from the user
            }

           switch(stoi(choice)){
             case 1:{
              if(oxenTotal < 200){
                int roundTotal = game.setOxen(oxenTotal, currentTot);
                if(roundTotal != -1){
                    oxenTotal += roundTotal;
                    currentTot = game.updateBill(currentTot, roundTotal);
                }
              }
              else if(oxenTotal >= 200)
                    cout << "You have purchased enough oxen." << endl;
                    
              if(currentTot >= 1000){
                    cout << "You don't have anymore money to spend. \n\n*****Let the journey begin!*****" << endl;
                    game.getInventory().modifyMoney(currentTot);
                    done = true;
             }
                   cout << endl;
                   break;
              
             }
             
             case 2:{
                if(foodTotal < 1000){
                  int roundTotal = game.setFood(foodTotal, currentTot);
                  if(roundTotal != -1){
                    foodTotal += roundTotal;
                    currentTot = game.updateBill(currentTot, roundTotal*game.getStore().getPrice(1));
                  }
                }
                else
                 cout << "You have purchased enough food." << endl;
                 
                if(currentTot >= 1000){
                    cout << "You don't have anymore money to spend.\n\n*****Let the journey begin!*****" << endl;
                    game.getInventory().modifyMoney(currentTot);
                    done = true;
                }
                
                cout << endl;
                break;
             }
             
             case 3:{
              
                  int roundTotal = game.setBullets(bulletTotal, currentTot);
                  if(roundTotal != -1)
                    currentTot = game.updateBill(currentTot, roundTotal*game.getStore().getPrice(2));

                if(currentTot >= 1000){
                    cout << "You don't have anymore money to spend.\n\n*****Let the journey begin!*****" << endl;
                    game.getInventory().modifyMoney(currentTot);
                    done = true;
                }
                
                cout << endl;
                break;
             }
             
             case 4:{
              int roundTotal = game.setWagon(wagonTotal, currentTot);
                  if(roundTotal != -1)
                    currentTot = game.updateBill(currentTot, roundTotal*game.getStore().getPrice(3));

                if(currentTot >= 1000){
                    cout << "You don't have anymore money to spend.\n\n*****Let the journey begin!*****" << endl;
                    game.getInventory().modifyMoney(currentTot);
                    done = true;
                }
                
                cout << endl;
                break;
             }
             
             case 5:{
              int roundTotal = game.setMed(medTotal, currentTot);
                  if(roundTotal != -1)
                    currentTot = game.updateBill(currentTot, roundTotal*game.getStore().getPrice(4));

                if(currentTot >= 1000){
                    cout << "You don't have anymore money to spend.\n\n*****Let the journey begin!*****" << endl;
                    game.getInventory().modifyMoney(currentTot);
                    done = true;
                }
                
                cout << endl;
                break;
             }
             
             case 6:
                  // quit 
                  //display total bill and inventory here
                  game.getInventory().modifyMoney(currentTot);
                  //cout << "\n*****Let the journey begin!*****" << endl;
                  done = true;
                  cout << endl;
                  break;

             default:
                    cout << "invalid input" << endl;
           }
           if(!done){
              game.getStore().displayStore();
           }
       }
            game.setMoneyAfterStore(-currentTot);
       
    }
    //else
        game.askForDate();
      cout << "\n*****Let the journey begin!*****\n" << endl; 
     // game.statusUpdate();
      string choice = "";
      bool done = false;
      bool passedMileStone = true;
       
    while(game.getInventory().getQuantity(1) > 0 && game.getInventory().getQuantity(0) > 0 && game.getPlayer().getAlive(0) && game.getJourney().getMiles() < 2040){
         
        while(choice != "4" && !done){
            game.statusUpdate();
            game.displayTurnChoices();
            getline(cin, choice);
             while(game.checkChocieSize(choice) < 49 || game.checkChocieSize(choice) > 52 || choice.length() == 0){ //checks that the user input a number, not anything else
              cout << "Please enter a valid selection." << endl;
              getline(cin, choice); //get the choice from the user
            }
            
             switch(stoi(choice)){
                 case 1:
                    game.rest();
                    cout << endl;
                    break;
                 case 2:{
                    passedMileStone= game.continueTrail();
                    break;
                 }case 3:
                    game.hunt();
                    break;
                 case 4:
                    cout << "Good bye. Thanks for playing!" << endl;
                    done = true;
                    cout << endl;
                    break;
                    
             }
             if(!done){
                bool gameEnd = game.determineMisfortune();
                 if((game.getInventory().getQuantity(3) && gameEnd) || !passedMileStone)
                    done = true;
                if(!done)
                    game.raiderAttack();
             }    
        }
    }
    
    if(game.getInventory().getQuantity(0) <= 0)
        cout << "\nSorry. You have died of starvation and could not make it to Oregon." << endl;
    else if(game.getInventory().getQuantity(3))
        cout << "\nSorry. Your wagon broke and you had no parts left to repair it so you could not make it to Oregon." << endl;
    else if( game.getInventory().getQuantity(0) <= 0)
        cout << "\nSorry. You have no more oxen and you could not make it to Oregon." << endl;
    else if(game.getPlayer().getAlive(0))
        cout << "\n Sorry. You died of a disease so you could not make it to Oregon." << endl;
    else if(game.getInventory().getMoney() < 50)
        cout << "\n Sorry. You could not cross a river milestone and thus you did not make it to Oregon." << endl;
    else if(game.getJourney().getMiles() >= 2040)
        cout << "**********Congratulations!!!! You successfully made it to Oregon!**********" << endl;
        //display stats
        
        
    ofstream myFile; //create an output file stream
    myFile.open("results.txt"); //open the file with the name from the parameter
    
    if(myFile.is_open()){ //if the file is open
                //leader name, miles travelled, food remaining, cash remaining
                myFile << "Leader name: " << game.getPlayer().getName(0) << endl;
                myFile << "Miles traveled: " << game.getJourney().getMiles() << endl;
                myFile << "Food remaining: " << game.getInventory().getQuantity(1) << "lbs" << endl;
                myFile << "Cash remaining: $" << game.getInventory().getMoney() << endl;
                
                cout << "Leader name: " << game.getPlayer().getName(0) << endl;
                cout << "Miles traveled: " << game.getJourney().getMiles() << endl;
                cout << "Food remaining: " << game.getInventory().getQuantity(1) << "lbs" << endl;
                cout << "Cash remaining: $" << game.getInventory().getMoney() << endl;
        }
    else //otherwise, if there's no file found
        cout << "file open failed" << endl; 

    myFile.close(); //close file
 }