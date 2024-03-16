#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct s_Config{
    string fileName;
    int maxTimeStamp;
    int refreshRate;
};

typedef struct s_Config Config;

struct s_State{
    int availableWorkers;
    int availableGoods;
};

typedef struct s_State State;

void loadConfig(string configFileName, Config &config);

void loadMap(Config config, vector<vector<char>> &map);

void display(vector<vector<char>> &map, State &state);

int countNeighbour(vector<vector<char>> map, int x, int y, int ch);

int countTotal(vector<vector<char>> map, int ch);

void process(vector<vector<char>> map1, vector<vector<char>> &map2, State &state);

bool isSameState(vector<vector<char>> map1, vector<vector<char>> map2);

void assign(vector<vector<char>> &map1, vector<vector<char>> map2);

#endif