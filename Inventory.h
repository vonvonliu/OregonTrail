#include <string>
using namespace std;

#ifndef INVENTORY_H
#define INVENTORY_H

//header file for the Library class
class Inventory{
    public:
        Inventory();
        Inventory(int amount[5], double); //default constructor
        int getQuantity(int index);
        double getMoney();
        void displayInventory();
        void modifyInventory(int index, int num);
        void setInventory(int index, int num);
        void modifyMoney(double amount);
        
        
    
    private:
        string items[5];
        int quantity[5];
        double money;
};

#endif