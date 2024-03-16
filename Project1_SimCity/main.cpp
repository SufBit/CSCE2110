#include <vector>
#include <iostream>

#include "operations.h"

using namespace std;

int main()
{
    Config config;
    State state;
    
    string configFileName = "config1.txt";
    
    cout << "Enter config file name : ";
    //cin >> configFileName;
    
    //Loading config
    loadConfig(configFileName, config);
    
    //Initialize the state
    state.availableWorkers = 0;
    state.availableGoods = 0;
    
    //Load the map state
    vector<vector<char>> map;
    loadMap(config, map);
    //Load the map state (a duplicate state)
    vector<vector<char>> map2;
    loadMap(config, map2);
    
    //For each iteration
    for(int i = 0; i < config.maxTimeStamp; i++)
    {
        if((i % config.refreshRate) == 0)   //Prints the state only during refresh rate 
        {
            cout << endl << "State " << i << endl;
            display(map, state);
        }
        
        process(map, map2, state);  //Process the iteration
        
        //Checks if the previous state and current state are same,
        // if then stop the iteration
        if(isSameState(map, map2))
            break;
        
        //Copy the new state to the current state map
        assign(map, map2);
    }
    
    return 0;
}