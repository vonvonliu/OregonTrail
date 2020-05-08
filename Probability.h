#include <string>
using namespace std;

#ifndef PROBABILITY_H
#define PROBABILITY_H

//header file for the Library class
class Probability{
    public:
        Probability(); //default constructor
        int randomNumbers(int min, int max);
        bool puzzle();
        int huntRabbit(int bullets);
        int huntFox(int bullets);
        int huntDeer(int bullets);
        int huntBear(int bullets);
        int huntMoose(int bullets);
  
    private:
        int randomNum;
        bool canHunt;
};

#endif