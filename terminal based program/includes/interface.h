#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <any>
#include <utility>
#include <fstream>
#include "stock.h"
#include "listdata.h"
#include "user.h"

using namespace std;

class Interface {

public:
    //displays useful information to the user when program is initialized
    void start();
    //runs console until exited
    void console();
    //gets input from user through command line and stores the words in a vector
    vector<string> commandInput();
    
    void buy_stock(Stock* new_stock, int stock_amount);

    void sell_stock(Stock* new_stock, int stock_amount);

    bool commandProcess(vector<string> command);
};

#endif