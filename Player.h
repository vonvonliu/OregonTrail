#include <string>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

//header file for the Library class
class Player{
    public:
        Player(); //default constructor
        void setName(string name, int index);
        string getName(int index);
        void setHealth(bool health, int index);
        bool getHealth(int index);
        void setAlive(bool alive, int index);
        bool getAlive(int index);
    
    private:
        string player [5];
        bool health [5];
        bool alive [5];
};

#endif