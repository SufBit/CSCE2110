#ifndef STARTEGY1_H
#define STARTEGY1_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "storeData.h"

using namespace std;

class strat1{

    public:

        char currMv; //Will store my current move 
        strdata B;       
        void getMove(int); //This will get my next move 
        //strdata(int len); //Constructor to see how many times you would like to run the code.  
        // void StoreMyMvs(char a);
        // void displayOutput(int, int); 
        // void getResults(); //This function will determine if I win, tie or lose
        // void BigBadEvilCode();//Function where you will insert your values.
        // void StoreMyMvs(char);//Function to store my moves inside of a vector

};



#endif