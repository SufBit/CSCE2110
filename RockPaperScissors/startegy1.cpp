#include "startegy1.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Strategy is implemented here, I assumed R<P<S as a cycle, if i win or lose then the cycle moves one step left, if i tie then the cycle moves one step to the right 
void strat1 :: getMove(int resu){

    //vector<char> PosMoves{'R', 'P', 'S'};
    //0 means a draw
    if (resu == 0){
        if (currMv == 'S'){
            currMv = 'R';
            B.StoreMyMvs(currMv);
        }
        else if (currMv == 'R'){
            currMv = 'P';
            B.StoreMyMvs(currMv);
        }
        else if (currMv == 'P'){
            currMv = 'S';
            B.StoreMyMvs(currMv);
        }        
    }

    //1 means a win or a loss
    else if (resu == 1){
        if (currMv == 'S'){
            currMv = 'P';
            B.StoreMyMvs(currMv);
        }
        else if (currMv == 'R'){
            currMv = 'S';
            B.StoreMyMvs(currMv);
        }
        else if (currMv == 'P'){
            currMv = 'R';
            B.StoreMyMvs(currMv);
        }        
    }
}




// To test out your bot you will input your bots results into a vector storeOpponentMv which has been assigned in the struct.
//Rock will be represented by R, Paper with P and Scissors with S.
//Example of running a random generator in this function:
// int choice = ((rand() % 3) + 1);

        // if (choice == 1){
        //     storeOpponentMv.push_back('S');
        // }
        // else if (choice == 2){
        //     storeOpponentMv.push_back('P');
        // }
        // else if (choice == 3){
        //     storeOpponentMv.push_back('R');
        // }
