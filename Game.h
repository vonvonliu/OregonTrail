#ifndef GAME_H
#define GAME_H

#include <string>
#include "Player.h"
#include "Store.h"
#include "Inventory.h"
#include "Journey.h"
#include "Probability.h"
using namespace std;


//header file for the Library class
class Game{
    public:
        Game();
        int checkChocieSize(string input);
        Player getPlayer();
        Store getStore();
        Inventory getInventory();
        Journey getJourney();
        int randomNumbers(int min, int max);
        void displayIntroInfo();
        void setPlayer();
        void displayInitialConditions();
        bool willVisitStore();
        double updateBill(double currentBill, double addition);
        double setOxen(double currentTotal, double currMon);
        int setFood(int currentTotal, double currMon);
        int setBullets(int currentTotal, double currMon);
        int setWagon(int currentTotal, double currMon);
        int setMed(int currentTotal, double currMon);
        void setMoneyAfterStore(double amount);
        void askForDate();
        void statusUpdate();
        void displayTurnChoices();
        void getSick();
        void oxenDies();
        bool wagonBroke();
        bool calcMisfortune();
        bool determineMisfortune();
        void raiderAttack();
        void rest();
        bool continueTrail();
        void hunt();
        void visitStore();
        void reachFort(int index);
        bool reachRiver(int index);
        
    
    private:
        Player player; //player object
        Store store; //store object
        Inventory inventory; //inventory object
        Journey journey; //journey object
        Probability probability;
        double bill;
        int mileStoneIndex;
};

#endif