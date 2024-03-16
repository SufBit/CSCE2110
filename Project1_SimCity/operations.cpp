#ifndef OPERATIONS_CPP
#define OPERATIONS_CPP

#include "operations.h"

//Loads the configuration from the config file
void loadConfig(string configFileName, Config &config)
{
    ifstream configFile(configFileName);
    
    string line;
    getline(configFile, line, ':');
    getline(configFile, config.fileName, '\n');
    getline(configFile, line, ':');
    configFile >> config.maxTimeStamp;
    getline(configFile, line, ':');
    configFile >> config.refreshRate;
    
    configFile.close();
}

//Loads the map file from the map file mentioned in the config
void loadMap(Config config, vector<vector<char>> &map)
{
    ifstream mapFile(config.fileName);
    
    string line, rowData;
    
    while (getline (mapFile, line)) {
        
        stringstream ss_line(line);
        vector<char> row;
        while(ss_line.good())
        {
            getline(ss_line, rowData, ',');
            row.push_back(rowData[0]);
            //cout << rowData[0] << ",";
        }
        //cout << endl;
        map.push_back(row);
    }
    
    mapFile.close();
}

//Prints the current state of the map
void display(vector<vector<char>> &map, State &state)
{
    for(int i = 0; i < map.size(); i++)
    {
        for(int j = 0; j < map[i].size(); j++)
        {
            cout << map[i][j] << ", ";
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "Available Workers : " << state.availableWorkers << endl;
    cout << "Available Goods   : " << state.availableGoods << endl;
    cout << endl;
}

//Counts the neighbour cells which matches to the character "ch"
int countNeighbour(vector<vector<char>> map, int x, int y, int ch)
{
    int sizeX = map.size(), sizeY = map[0].size(), count = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int x1 = x + i, y1 = y + j;
            if(i == 0 && j == 0);
            else if(x1 >= 0 && y1 >= 0 && x1 < sizeX && y1 < sizeY)
            {
                if(map[x1][y1] == ch)
                    count++;
            }
        }
    }
    
    return count;
}

//Counts the total number of cells which matches to the character "ch"
int countTotal(vector<vector<char>> map, int ch)
{
    int sizeX = map.size(), sizeY = map[0].size(), count = 0;
    for(int i = 0; i < map.size(); i++)
    {
        for(int j = 0; j < map[i].size(); j++)
        {
            if(i >= 0 && j >= 0 && i < sizeX && j < sizeY)
            {
                if(map[i][j] == ch)
                    count++;
            }
        }
    }
    
    return count;
}

//Performs the iteration which decides to increase and manages the population
void process(vector<vector<char>> map1, vector<vector<char>> &map2, State &state)
{
    int processCommercialPerStep = 0;
    int processIndustrialPerStep = 0;
    
    for(int i = 0; i < map1.size(); i++)
    {
        for(int j = 0; j < map1[i].size(); j++)
        {
            if(state.availableWorkers >= 1 && state.availableGoods >= 1 && map1[i][j] == 'C' && (countNeighbour(map1, i, j, 'T') > 0 || countNeighbour(map1, i, j, '#') > 0))
            {
                //if(processCommercialPerStep == 0)
                {
                    //cout << "Hit 1" << endl;
                    map2[i][j] = '1';
                    state.availableWorkers--;
                    state.availableGoods--;
                    processCommercialPerStep++;
                }
            }
            
            if(state.availableWorkers >= 1 && state.availableGoods >= 1 && map1[i][j] == 'C' && countNeighbour(map1, i, j, '1') > 0)
            {
                //if(processCommercialPerStep == 0)
                {
                    //cout << "Hit 1" << endl;
                    map2[i][j] = '1';
                    state.availableWorkers--;
                    state.availableGoods--;
                    processCommercialPerStep++;
                }
            }
            
            if(state.availableWorkers >= 2 && map1[i][j] == 'I' &&  countNeighbour(map1, i, j, '1') == 0 && (countNeighbour(map1, i, j, 'T') > 0 || countNeighbour(map1, i, j, '#') > 0))
            {
                if(processIndustrialPerStep == 0)
                {
                    map2[i][j] = '1';
                    state.availableWorkers -= 2;
                    state.availableGoods++;
                    processIndustrialPerStep++;
                }
            }
            
            if(state.availableWorkers >= 2 && map1[i][j] == 'I' && countNeighbour(map1, i, j, '1') > 0)
            {
                if(processIndustrialPerStep == 0)
                {
                    map2[i][j] = '1';
                    state.availableWorkers -= 2;
                    state.availableGoods++;
                    processIndustrialPerStep++;
                }
            }
            
            if(map1[i][j] == 'R' && (countNeighbour(map1, i, j, '1') > 0 || countNeighbour(map1, i, j, 'T') > 0 || countNeighbour(map1, i, j, '#') > 0))
            {
                map2[i][j] = '1';
                state.availableWorkers++;
            }
            
            if(map1[i][j] == '1' && countNeighbour(map1, i, j, '1') >= 2)
            {
                map2[i][j] = '2';
                state.availableWorkers++;
            }
            
            if(map1[i][j] == '2' && countNeighbour(map1, i, j, '2') >= 4)
            {
                map2[i][j] = '3';
                state.availableWorkers++;
            }
            
            if(map1[i][j] == '3' && countNeighbour(map1, i, j, '3') >= 6)
            {
                map2[i][j] = '3';
                state.availableWorkers++;
            }
        }
    }
}

//Checks whether the previous state and currect state of the map are same
bool isSameState(vector<vector<char>> map1, vector<vector<char>> map2)
{
    for(int i = 0; i < map1.size(); i++)
    {
        for(int j = 0; j < map1[i].size(); j++)
        {
            if(map1[i][j] != map2[i][j])
                return false;
        }
    }
    
    return true;
}

//Assign the state of "map 2" to the "map 1"
void assign(vector<vector<char>> &map1, vector<vector<char>> map2)
{
    for(int i = 0; i < map1.size(); i++)
    {
        for(int j = 0; j < map1[i].size(); j++)
        {
            map1[i][j] = map2[i][j];
        }
    }
}

#endif