#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std;

Inventory::Inventory(){
    items[0] = "Oxen";
    items[1] = "Food";
    items[2] = "Bullets";
    items[3] = "Wagon Parts (wheel, tongue, axle)";
    items[4] = "Medical Kit";
    for(int i = 0; i < 5; i++)
        quantity[i] = 0;
    money = 1000;
}

Inventory::Inventory(int amount[5], double dollars){
    items[0] = "Oxen";
    items[1] = "Food";
    items[2] = "Bullets";
    items[3] = "Wagon Parts (wheel, tongue, axle)";
    items[4] = "Medical Kit";
    
    for(int i = 0; i < 5; i++)
        quantity[i] = amount[i];
    money = dollars;
}

int Inventory::getQuantity(int index){
    return quantity[index];
}

void Inventory::modifyMoney(double amount){
    money += amount;
}

double Inventory::getMoney(){
    return money;
}

void Inventory::displayInventory(){
    cout << "Here is what is in your inventory at the moment:" << endl;
    cout << "1. " << items[0] << ": " << quantity[0] << " yoke(s)" << endl;
    cout << "2. " << items[1] << ": " << quantity[1] << " pound(s)" << endl;
    cout << "3. " << items[2] << ": " << quantity[2] << " boxe(s)" << endl;
    cout << "4. " << items[3] << ": " << quantity[3] << " part(s)" << endl;
    cout << "5. " << items[4] << ": " << quantity[4] << " kit(s)" << endl;
}

void Inventory::modifyInventory(int index, int num){
    quantity [index] += num;
}

void Inventory::setInventory(int index, int num){
    quantity [index] = num;
}
