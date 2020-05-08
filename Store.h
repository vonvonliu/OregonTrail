#include <string>
using namespace std;

#ifndef STORE_H
#define STORE_H

//header file for the Library class
class Store{
    public:
        Store(); //default constructor
        
        string getItemName(int index);
        double getPrice(int index);
        void displayStore();
        void incrementPrices(int fort);
        double calcBill(double currentCost, double increment);
        
        
    
    private:
        string items[5];
        double prices[5];
        
};

#endif