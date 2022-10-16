#include "interface.h"

Interface::Interface() {}
//Sets pointer to user that will be used
Interface::Interface(User* user) :user(user) {}

void Interface::console()
{
    vector<string> command;
    do
    {
        cout << "$ ";
        command = commandInput();
    } while (commandProcess(command));
}

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
}

bool Interface::commandProcess(vector<string> commands) {
    if (commands.size() == 0) {return 1;}
    if (commands.at(0) == "user") {user_command(commands); return 1;}
    if (commands.at(0) == "login") {login(); return 1;}
    if (commands.at(0) == "logout") {logout(); return 1;}
    if (commands.at(0) == "sign-up") {create_user(); return 1;}
    if (commands.at(0) == "stock") {stock_command(commands); return 1;}
    if (commands.at(0) == "exit") {return 0;}
    cout << "$" << commands.at(0) << " is not valid command." << endl;
    cout << "$Please refer to the \"help\" for a list of avaliable commands" << endl;
    cout << endl;
}

void Interface::user_command(vector<string> commands) {
    if (commands.size() == 1) {error(commands); return;}
    if (commands.size() == 2) {
        if (commands.at(1) == "stock") {user->list_data(); return;}
        if (commands.at(1) == "delete") {delete_user(); return;}
        error(commands);
        return;
    }
    if (commands.size() == 3) {
        if (commands.at(1) == "stock")
        {
            for (int i = 0; i = user->stock->size(); i++) {
                if (user->stock->at(i)->get_name() == commands.at(2)) {
                    user->list_data(user->stock->at(i)->get_name());
                    return;
                }
            }
            cout << "$You do not own any of this stock" << endl;
            cout << "$To show your owned stock type:" << endl;
            cout << "$user stock" << endl;
            cout << endl;
        }
    }
}

void Interface::read_stock() {
    ifstream inFile("stock.csv");
    string data;
    while (getline(inFile, data))
    {
        vector<string> line;
        istringstream ss(data);
        string temp;
        while (getline(ss, temp, ','))
            line.push_back(temp);
        Stock *stock_obj = new Stock(line.at(0), line.at(1), stod(line.at(2)), stoi(line.at(3)));
        avaliable_stock->push_back(stock_obj);8
    }
}

void Interface::buy_stock(Stock *new_stock, int stock_amount)
{

}

void Interface::sell_stock(Stock *new_stock, int stock_amount)
{

}

void Interface::error(vector<string> error) {

}