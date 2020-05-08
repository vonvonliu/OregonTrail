#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#ifndef JOURNEY_H
#define JOURNEY_H

class Journey{
    public:
        Journey(); //default constructor
        Journey(int paramDay, int paramMonth);
        int getYear();
        int getMonth();
        int getDay();
        int setMonth(int num);
        int setDay(int num);
        int getMonthDays(int index);
        string getMonthNames(int index);
        int changeMonth(int currMonth,int days);
        void updateDate(int days);
        void modifyMiles(int num);
        int getMiles();
        int getDistLeft();
        void setDistLeft();
        int split(string str, char c, string array[], int size);
        int setRiver(string fName);
        int setFort(string fName);
        string getFortName(int index);
        string getRiverName(int index);
        int getDist(int index);
        int getRivWid(int index);
        int getRivDist(int index);
        int getFortDist(int index);
        
    
    private:
        int month;
        int day;
        int year = 1847;
        int miles;
        int distLeft;
        int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string monthNames[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        string riverNames[4];
        string fortNames[6];
        int riverWidth[4];
        int riverDist[4];
        int fortDist[6];
        int dist[10];
        
};

#endif