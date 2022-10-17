#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <any>
#include <utility>
#include <string>
#include <cstdio>
#include <fstream>
#include "stock.h"
#include "listdata.h"
#include "user.h"

using namespace std;

class Interface : public Listdata
{
private:
    User * user;
public:
    vector<Stock*> *avaliable_stock;
    //default constructor
    Interface::Interface();
    //recieves pointer to user that will be used
    Interface::Interface(User*);
    // displays useful information to the user when program is initialized
    void start();
    // runs console until exited
    void console();
    // gets input from user through command line and stores the words in a vector
    vector<string> commandInput();
    //attempts to buy stock and store it in the current user
    void buy_stock(string, int);
    //attempts to sell stock from the user
    void sell_stock(string, int);
    //runs through the different protocalls for the user command input
    bool commandProcess(vector<string>);
    //displays a help screen
    void help();
    //displays all stocks avaliable for the user to buy
    void list_data();
    //displays information on a specific stock selected by the user
    void list_data(string);
    //creates new user
    void create_user();
    //deletes user
    void delete_user();
    //creates new stock
    void create_stock();
    //deletes stock
    void delete_stock();
    //holds commands that changes or displays user data
    void user_command(vector<string>);
    //asks for username and password then sets the user object to the saved user
    void login();
    //changes back to new user object
    void logout();
    //runs through list of different stock commands
    void stock_command(vector<string>);
    //reads the stock csv and stores the data in an Stock object vector
    void read_stock();
    //writes the stock data store in the stock vector to the stock csv file
    void write_stock();
    //reads user csv file and stores into user object
    void read_user();
    //writes the user object to the user csv
    void write_user();
};

#endif