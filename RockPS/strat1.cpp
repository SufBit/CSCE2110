#include "strat1.h"

//Constructor
RPS :: RPS(int len){

    sizeC = len;
    BigBadEvilCode();
    StoreMvs('P'); //The first move I will play is Paper, which will store into a vector
    getResults(); //Once my move is stored in vector this function will determine my outcome.
    
}


void RPS :: StoreMvs(char a){

    B.mvsStored.push_back(a); //Storing each character in vector.
    currMv = a; //Will assign each move i make to current move. 
    
}

//Strategy is implemented here, I assumed R<P<S as a cycle, if i win or lose then the cycle moves one step left, if i tie then the cycle moves one step to the right 
void RPS :: getMove(int resu){

    //vector<char> PosMoves{'R', 'P', 'S'};
    //0 means a draw
    if (resu == 0){
        if (currMv == 'S'){
            currMv = 'R';
            StoreMvs(currMv);
        }
        else if (currMv == 'R'){
            currMv = 'P';
            StoreMvs(currMv);
        }
        else if (currMv == 'P'){
            currMv = 'S';
            StoreMvs(currMv);
        }        
    }

    //1 means a win or a loss
    else if (resu == 1){
        if (currMv == 'S'){
            currMv = 'P';
            StoreMvs(currMv);
        }
        else if (currMv == 'R'){
            currMv = 'S';
            StoreMvs(currMv);
        }
        else if (currMv == 'P'){
            currMv = 'R';
            StoreMvs(currMv);
        }        
    }
}

//This function checks the results of the game. 
void RPS :: getResults(){

    int result = 0;
    int trackRound = 0;

    //Initialized for loop to end at sizeC, which is the total number of rounds, which fixed my error of vector going out of range, and inputs being stored incorrectly in vector. 
    for (int i = 0; i < sizeC; i++){

        if(B.mvsStored.at(i) == B.storeOpponentMv.at(i)){
            result = 0; // Represents a tie
            B.tieC++;
            B.tieB++;
            //break;
            getMove(result);
            // continue;
        }

        //If condition ends in a loss for my bot.
        else if (B.mvsStored.at(i) == 'R' && B.storeOpponentMv.at(i) == 'P'){
            result = 1; // Represents loss.
            B.lostC++;
            B.winB++;
            //break;
            getMove(result);
            // continue;
        }

        else if (B.mvsStored.at(i) == 'P' && B.storeOpponentMv.at(i) == 'S'){
            result = 1; //Representing win or loss.
            B.lostC++;
            B.winB++;
            //break;
            getMove(result);
            // continue;
        }

        else if (B.mvsStored.at(i) == 'S' && B.storeOpponentMv.at(i) == 'R'){
            result = 1; //Representing win or loss.
            B.lostC++;
            B.winB++;
            //break;
            getMove(result);
            // continue;
        }

        else if (B.mvsStored.at(i) == 'R' && B.storeOpponentMv.at(i) == 'S'){
            result = 1; //Representing win or loss.
            B.winC++;
            B.lostB++;
            //break;
            getMove(result);
            // continue;
        }

        if (B.mvsStored.at(i) == 'P' && B.storeOpponentMv.at(i) == 'R'){
            result = 1; //Representing win or loss.
            B.winC++;
            B.lostB++;
            //break;
            getMove(result);
            // continue;
        }

        else if (B.mvsStored.at(i) == 'S' && B.storeOpponentMv.at(i) == 'P'){
            result = 1; //Representing win or loss.
            B.winC++;
            B.lostB++;
            //break;
            getMove(result);
            // continue;
        }
        trackRound++;
        displayOutput(trackRound, i); //Used to display the rounds. 
        BigBadEvilCode(); //Function will read in opponenets input
     
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
void RPS :: BigBadEvilCode(){

        //Strategy 2.
        int choice = ((rand() % 3) + 1); //Get random number between 1 and 3

        if (choice == 1){
            B.storeOpponentMv.push_back('S');
        }
        else if (choice == 2){
            B.storeOpponentMv.push_back('P');
        }
        else if (choice == 3){
            B.storeOpponentMv.push_back('R');
        }
}

void RPS :: displayOutput(int i, int veci){

    //Calulcations For Random Alogrithim
    double totalB = B.winB + B.tieB + B.lostB;
    double winPerB = (double(B.winB)/totalB)*100;
    double tiePerB = (double(B.tieB)/totalB)*100;
    double losePerB = (double(B.lostB)/totalB)*100;

    //Calulations For my Algorithim
    double total = B.winC + B.tieC + B.lostC;
    double winPer = (double(B.winC)/total)*100;
    double tiePer = (double(B.tieC)/total)*100;
    double losePer = (double(B.lostC)/total)*100;

    cout << "Round#" << i << endl;
    cout << "Win: " << B.winC << " Win Percentage is " << winPer << endl;
    cout << "Tied: " << B.tieC << " Tie Percentage is " << tiePer << endl;
    cout << "Loss: " << B.lostC << " lose Percentage is " << losePer << endl;

    //cout << "What I played " << B.mvsStored.at(veci) << " vs what you played " << B.storeOpponentMv.at(veci) << endl;

    if (i >= sizeC){
        FinalOutput(winPerB, tiePerB, losePerB, winPer, tiePer, losePer);
    }
   
}

//This will print out final output showing who has won
void RPS :: FinalOutput(double w, double tie, double l, double wb, double tb, double lb){

    //This will check which program will have more wins
    if (B.winC > B.winB){
        cout << "Who's the winner:" << endl;
        cout << "Winning Algorithim: " << "Zeijian Alogorithim (Mine)" << endl;
        cout << "Win percentage: " << wb << endl;
        cout << "Tie Percentage: " << tb << endl;

        cout << "Who's the loser:" << endl;
        cout << "Losing Algorithim: " << "Random Generator" << endl;
        cout << "Win percentage: " << w << endl;
        cout << "Tie Percentage: " << tie << endl;
    }

    else if (B.winC < B.winB){

        cout << "Who's the winner:" << endl;
        cout << "Winning Algorithim: " << "Random Generator" << endl;
        cout << "Win percentage: " <<  w << endl;
        cout << "Tie Percentage: " << tie << endl;

        cout << "Who's the loser:" << endl;
        cout << "Losing Algorithim: " << "Zeijiang Algorithim" << endl;
        cout << "Win percentage: " << wb << endl;
        cout << "Tie Percentage: " << tb << endl;
    }

}
