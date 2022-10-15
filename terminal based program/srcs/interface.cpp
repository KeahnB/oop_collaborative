#include "interface.h"

void Interface::console()
{
    vector<string> command;
    do
    {
        cout << "$ ";
        command = commandInput();
    } while (true);
};

vector<string> Interface::commandInput()
{
    // stores the command input from the user
    string input;
    // stores seperate command words from input
    vector<string> commands;
    // gets a command input from the user and stores it in input string
    getline(cin, input);
    // onject class of istringstream
    istringstream ss(input);
    // stores the stream string
    string store;
    // splits stream string by ' ' and pushes it to command vector
    while (getline(ss, store, ' '))
        commands.push_back(store);
    return commands;
};

bool Interface::commandProcess(vector<string> commands){

};
