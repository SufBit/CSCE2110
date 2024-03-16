#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "storeData.h"



//Constructor
strdata :: strdata(int len){

    class strat1;
    sizeC = len;
    BigBadEvilCode();
    StoreMyMvs('P');
    getResults(); //Once my move is stored in vector this function will determine my outcome. 
    
}
void strdata :: StoreMyMvs(char a){

    mvsStored.push_back(a); //Storing each character in vector.
    //currMv = a; //Will assign each move i make to current move. 
    
}

void strdata :: BigBadEvilCode(){

    int choice = ((rand() % 3) + 1);

        if (choice == 1){
            storeOpponentMv.push_back('S');
        }
        else if (choice == 2){
            storeOpponentMv.push_back('P');
        }
        else if (choice == 3){
            storeOpponentMv.push_back('R');
        }
    

}

void strdata :: displayOutput(int i, int veci){

    double total = winC + tieC + lostC;
    double winPer = (double(winC)/total)*100;
    double tiePer = (double(tieC)/total)*100;
    double losePer = (double(lostC)/total)*100;

    cout << "Round#" << i << endl;
    cout << "Win: " << winC << " Win Percentage is " << winPer << endl;
    cout << "Tied: " << tieC << " Tie Percentage is " << tiePer << endl;
    cout << "Loss: " << lostC << " lose Percentage is " << losePer << endl;

    cout << "What I played " << mvsStored.at(veci) << " vs what you played " << storeOpponentMv.at(veci) << endl;
    
}

//This function checks the results of the game. 
void strdata :: getResults(){

    int result = 0;
    int trackRound = 0;

    //Initialized for loop to end at sizeC, which is the total number of rounds, which fixed my error of vector going out of range, and inputs being stored incorrectly in vector. 
    for (int i = 0; i < sizeC; i++){

        if(mvsStored.at(i) == storeOpponentMv.at(i)){
            result = 0; // Represents a tie
            tieC++;
            //break;
            s1.getMove(result);
            // continue;
        }

        //If condition ends in a loss for my bot.
        else if (mvsStored.at(i) == 'R' && storeOpponentMv.at(i) == 'P'){
            result = 1; // Represents loss.
            lostC++;
            //break;
            s1.getMove(result);
            // continue;
        }

        else if (mvsStored.at(i) == 'P' && storeOpponentMv.at(i) == 'S'){
            result = 1; //Representing win or loss.
            lostC++;
            //break;
            s1.getMove(result);
            // continue;
        }

        else if (mvsStored.at(i) == 'S' && storeOpponentMv.at(i) == 'R'){
            result = 1; //Representing win or loss.
            lostC++;
            //break;
            s1.getMove(result);
            // continue;
        }

        else if (mvsStored.at(i) == 'R' && storeOpponentMv.at(i) == 'S'){
            result = 1; //Representing win or loss.
            winC++;
            //break;
            s1.getMove(result);
            // continue;
        }

        if (mvsStored.at(i) == 'P' && storeOpponentMv.at(i) == 'R'){
            result = 1; //Representing win or loss.
            winC++;
            //break;
            s1.getMove(result);
            // continue;
        }

        else if (mvsStored.at(i) == 'S' && storeOpponentMv.at(i) == 'P'){
            result = 1; //Representing win or loss.
            winC++;
            //break;
            s1.getMove(result);
            // continue;
        }
        trackRound++;
        displayOutput(trackRound, i); //Used to display the rounds. 
        BigBadEvilCode(); //Function will read in opponenets input
     
 }



}