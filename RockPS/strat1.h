#ifndef START1
#define START1

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "storeData.h"

using namespace std;

struct RPS{

        // int winC = 0; //Initialize number of wins
        // int tieC = 0; //Initialize number of ties
        // int lostC = 0; //initalize number of losses
        int sizeC = 0; //Will determine how many rounds you want to run
        char currMv; //Will store my current move
        // vector<char> mvsStored; //To store my bots moves
        // vector<char> storeOpponentMv; //To store your bots moves
        RPS(int len); //Constructor to see how many times you would like to run the code.          
        void StoreMvs(char);//Function to store my moves inside of a vector
        void getMove(int); //This will get my next move 
        void displayOutput(int, int); 
        void getResults(); //This function will determine if I win, tie or lose
        void BigBadEvilCode();//Function where you will insert your values.
        void FinalOutput(double, double ,double, double, double, double);
        strData B;

};

#endif