#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <any>
#include <utility>
#include <fstream>
using namespace std;

class Interface {

public:
    //displays useful information to the user when program is initialized
    void start();
    //runs console until exited
    void console();
    //gets input from user through command line and stores the words in a vector
    vector<string> commandInput();

    bool commandProcess(vector<string> command);
};

#endif