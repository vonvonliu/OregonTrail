#include <string>
#include <iostream>
#include <fstream>
#include "Journey.h"
using namespace std;

Journey::Journey(){
    day = 28;
    month = 3;
    miles = 0;
    distLeft = 2040;
    setRiver("river.txt");
    setFort("forts.txt");
    int r = 0;
    int f = 0;
    for(int i = 0; i < 10; i++){
        if(r < 4){
            if(riverDist[r] < fortDist[f]){
                dist[i] = riverDist[r];
                r++;
            }else{
                dist[i] = fortDist[f];
                f++;
            }
        }
    }
    dist[8] = fortDist[4];
    dist[9] = fortDist[5];
}

Journey::Journey(int paramDay, int paramMonth){
    day = paramDay;
    month = paramMonth;
    miles = 0;
    distLeft = 2040;
}

int Journey::getYear(){
    return year;
}

int Journey::getMonth(){
    return month;
}

int Journey::getDay(){
    return day;
}

int Journey::setMonth(int num){
    month = num;
}

int Journey::setDay(int num){
    day = num;
}

int Journey::getMonthDays(int index){
    return monthDays[index];
}

string Journey::getMonthNames(int index){
    return monthNames[index];
}


int Journey::changeMonth(int currMonth, int days){
    bool setDay = false;
    switch(currMonth){
        case 1:
            if(days + day > getMonthDays(1)){
                day = (day + days) - getMonthDays(1);
                setDay = true;
                month++;
            }
            break;
        case 2:
            if(days + day > getMonthDays(2)){
                day = (day + days) - getMonthDays(2);
                setDay = true;
                month++;
            }break;
        case 3:
            if(days + day > getMonthDays(3)){
                day = (day + days) - getMonthDays(3);
                setDay = true;
                month++;
            }break;
        case 4:
            if(days + day > getMonthDays(4)){
                day = (day + days) - getMonthDays(4);
                setDay = true;
                month++;
            }break;
        case 5:
            if(days + day > getMonthDays(5)){
                day = (day + days) - getMonthDays(5);
                setDay = true;
                month++;
            }break;
                
        case 6:
            if(days + day > getMonthDays(6)){
                day = (day + days) - getMonthDays(6);
                setDay = true;
                month++;
             }break;   
        case 7:
            if(days + day > getMonthDays(7)){
                day = (day + days) - getMonthDays(7);
                setDay = true;
                month++;
             }break; 
        case 8:
            if(days + day > getMonthDays(8)){
                day = (day + days) - getMonthDays(8);
                setDay = true;
                month++;
            }break;  
        case 9:
            if(days + day > getMonthDays(9)){
                day = (day + days) - getMonthDays(9);
                setDay = true;
                month++;
             }break;   
        case 10:
            if(days + day > getMonthDays(10)){
                day = (day + days) - getMonthDays(10);
                setDay = true;
                month++;
            }break;
        case 11:
            if(days + day > getMonthDays(11)){
                day = (day + days) - getMonthDays(11);
                setDay = true;
                month++;
            }break;
        case 12:
            if(days + day > getMonthDays(12)){
                day = (day + days) - getMonthDays(currMonth);
                setDay = true;
                month++;
            }break;
    }
    if(!setDay)
        day += days;
    return month;
}

void Journey::updateDate(int days){
    month = changeMonth(getMonth(), days);
}

void Journey::modifyMiles(int num){
    miles += num;
}

int Journey::getMiles(){
    return miles;
}

int Journey::getDistLeft(){
    return distLeft;
}

void Journey::setDistLeft(){
    distLeft -= miles;
}

/* split function
 * the function to split the given string into array of string with respect to a delimiter
 *
 * @param : string , the string we are going to split
 * @param : char, the delimiter
 * @param : string array, the array of string we save after spliting
 * @param : int, size of the  indicates the maximum number of split-apart string pieces
*/

 int Journey::split (string str, char c, string array[], int size){
    if (str.length() == 0) 
         return 0; 
     
    string word = ""; 
    int count = 0; 
    str = str + c;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == c){
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        }else
            word = word + str[i];
    }
    return count ;
 }
 
int Journey::setRiver(string fName){
    int lines = 1;
    int i = 0;
    int j = 0;
    string tempArr [4]; //new temporary array for saving what is retrieved from the getline
    ifstream myFile; //create an input file stream
    myFile.open(fName); //open the file with the name from the parameter
    
    if(myFile.is_open()){ //if the file is open
        string line = ""; //string variable that saves the value on each line
        while((getline(myFile, line))){ //get the line from the file
            if(lines % 2 == 1){
                if(i < 4)
                    riverNames[i] = line; 
                i++;
                lines++;
            }else{
                if(j < 4)
                    tempArr[j] = line;
                j++;
                lines++;
            }
                
        }
        
        string riverInfo [2];
        split(tempArr[0], 'm', riverInfo, 2);
        riverWidth[0] = stoi(riverInfo[1].substr(9, 1));
        riverDist[0] = stoi(riverInfo[0]);

        split(tempArr[1], 'm', riverInfo, 2);
        riverWidth[1] = stoi(riverInfo[1].substr(9, 1));
        riverDist[1] = stoi(riverInfo[0]);
        
        split(tempArr[2], 'm', riverInfo, 2);
        riverWidth[2] = stoi(riverInfo[1].substr(9, 1));
        riverDist[2] = stoi(riverInfo[0]);
        
        split(tempArr[3], 'm', riverInfo, 2);
        riverWidth[3] = stoi(riverInfo[1].substr(9, 1));
        riverDist[3] = stoi(riverInfo[0]);
        
            
    }
    else //otherwise, if there's no file found
        return -1; //return -1

    myFile.close(); //close file
    return 0;
}

int Journey::setFort(string fName){
    int lines = 1;
    int i = 0;
    int j = 0;
    string tempArr [6]; //new temporary array for saving what is retrieved from the getline
    ifstream myFile; //create an input file stream
    myFile.open(fName); //open the file with the name from the parameter
    
    if(myFile.is_open()){ //if the file is open
        string line = ""; //string variable that saves the value on each line
        while((getline(myFile, line))){ //get the line from the file
            if(lines % 2 == 1){
                if(i < 6)
                    fortNames[i] = line; 
                i++;
                lines++;
            }else{
                if(j < 6)
                    tempArr[j] = line;
                j++;
                lines++;
            }
                
        }
        
        string fortInfo [2];
        for(int i = 0; i < 6; i++){
           split(tempArr[i], 'm', fortInfo, 2);
           fortDist[i] = stoi(fortInfo[0]); 
        }
    
    }
    else //otherwise, if there's no file found
        return -1; //return -1

    myFile.close(); //close file
    return 0;
}

string Journey::getFortName(int index){
    return fortNames[index];
}

string Journey::getRiverName(int index){
    return riverNames[index];
}

int Journey::getDist(int index){
    return dist[index];
}

int Journey::getRivWid(int index){
    return riverWidth[index];
}

int Journey::getRivDist(int index){
    return riverDist[index];
}

int Journey::getFortDist(int index){
    return fortDist[index];
}

