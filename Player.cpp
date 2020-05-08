#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

/*
Default constructor for player class
*/
Player::Player(){ //default constructor
    for(int i = 0; i < 5; i++){
        player[i] = "";
        health[i] = true;
        alive[i] = true;
    }
}

void Player::setName(string name, int index){
    if(index >= 0 && index < 5)
        player[index] = name;
} 

string Player::getName(int index){
    if(index >= 0 && index < 5)
        return player[index];
    return "";
}

void Player::setHealth(bool healthy, int index){
    if(index >= 0 && index < 5)
        health[index] = healthy;
}

bool Player::getHealth(int index){
    if(index >= 0 && index < 5)
        return health[index];
    return false;
}

void Player::setAlive(bool living, int index){
    if(index >= 0 && index < 5)
        alive[index] = living;
}

bool Player::getAlive(int index){
    if(index >= 0 && index < 5)
        return alive[index];
    return false;
}