#include "Store.h"
#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std;

Store::Store(){
    items[0] = "Oxen";
    items[1] = "Food";
    items[2] = "Bullets";
    items[3] = "Wagon Parts (wheel, tongue, axle)";
    items[4] = "Medical Kit";
    
    prices[0] = 40;
    prices[1] = 0.5;
    prices[2] = 2;
    prices[3] = 20;
    prices[4] = 25;
}

string Store::getItemName(int index){
    if(index > -1 && index < 5)
        return items[index];
    else{
        cout << "Invalid input" << endl;
        return "";
    } 
}

double Store::getPrice(int index){
    if(index > -1 && index < 5)
        return prices[index];
    else{
        cout << "Invalid input" << endl;
        return -1;
    } 
}

void Store::displayStore(){
    cout << "\nWhat would you like to buy? " << endl;
    cout << "1. " << items[0] << ": $" << prices[0] << "/ yoke" << endl;
    cout << "2. " << items[1] << ": $" << prices[1] << "/ pound" << endl;
    cout << "3. " << items[2] << ": $" << prices[2] << "/ box" << endl;
    cout << "4. " << items[3] << ": $" << prices[3] << "/ part" << endl;
    cout << "5. " << items[4] << ": $" << prices[4] << "/ kit" << endl;
    cout << "6. Leave store" << endl;
}

void Store::incrementPrices(int fort){
    double increment = 0;
    for(int i = 0; i < fort; i++)
        increment += 0.25;
        
    for(int i = 0; i < 7; i++)
        prices[i] *= increment;
}

double Store::calcBill(double currentCost, double increment){
    cout << "Current bill: $" << currentCost + increment;
    return currentCost + increment;
}
