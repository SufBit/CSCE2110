#ifndef STOREDATA_H
#define STOREDATA_H

#include <iostream>
#include <vector>

using namespace std;

//Struct to store all the data. 
struct strData{

        int winC = 0; //Initialize number of wins
        int tieC = 0; //Initialize number of ties
        int lostC = 0; //initalize number of losses
        int sizeC = 0; //Will determine how many rounds you want to run
        int winB = 0; //Initialize number of wins
        int tieB = 0; //Initialize number of ties
        int lostB = 0; //Initialize number of loses for bot
        vector <char> mvsStored; //To store my bots moves
        vector <char> storeOpponentMv; //To store your bots moves

};


#endif