#ifndef STOREDATA_H
#define STOREDATA_H


#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "startegy1.h"

using namespace std;

class strdata{

    public:

        strat1 s1;
        int winC = 0; //Initialize number of wins
        int tieC = 0; //Initialize number of ties
        int lostC = 0; //initalize number of losses
        int sizeC = 0; //Will determine how many rounds you want to run
        vector<char> mvsStored; //To store my bots moves
        vector<char> storeOpponentMv; //To store your bots moves   
        strdata(int len); //Constructor to see how many times you would like to run the code.  
        void displayOutput(int, int); 
        void getResults(); //This function will determine if I win, tie or lose
        void BigBadEvilCode();//Function where you will insert your values.
        void StoreMyMvs(char);//Function to store my moves inside of a vector

};






#endif