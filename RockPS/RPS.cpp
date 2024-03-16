#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "strat1.h"

using namespace std;

int main(){

    srand(time(NULL)); //For my Random Bot algorithim
    int length, currScrp;
    cout << "Enter how many times you would like to run the program: " << endl;
    cin >> length;
    cout << "How many times would you like to print out the results to the screen? " << endl;
    cin >> currScrp;
    RPS o1(length); //Object that will call constructor
    cout << endl;
    
    return 0;
}
