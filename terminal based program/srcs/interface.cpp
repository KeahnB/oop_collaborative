#include "interface.h"

Interface::Interface() {}
//Sets pointer to user that will be used
Interface::Interface(User* user) :user(user) {}

void Interface::console()
{
    read_stock();
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
    // object class of istringstream
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
        avaliable_stock->push_back(stock_obj);
    }
}

void Interface::create_stock()
{
    if (user->get_name() == "N/A") {
        cout << "You must login as a user to use this command" << endl;
        cout << endl;
        return;
    }
    string stock_name;
    cout << "$Enter stock name you want to add: " << endl;
    getline(cin, stock_name);
    for (int i = 0; i < avaliable_stock->size(); i++)
    {
        if (stock_name == avaliable_stock->at(i)->get_name())
        {
            cout << "$The stock you tried to create already exists in the system" << endl;
            cout << "$Please choose a different name for the stock" << endl;
            cout << endl;
            return;
        }
    }
    cout << "$Enter the current pricing of the stock:" << endl;
    string stock_price, stock_amount;
    getline(cin, stock_price);
    cout << "$Enter the current number of avaliable stock:" << endl;
    getline(cin, stock_amount);
    Stock *stock_obj = new Stock(stock_name, user->get_name(), stod(stock_price), stoi(stock_amount));
    avaliable_stock->push_back(stock_obj);
    write_stock();
}

void Interface::write_stock() {
    ofstream outFile;
    outFile.open("stock.csv", ios::out | ios::trunc);
    for (int i = 0; i < avaliable_stock->size(); i++)
    {
        outFile << avaliable_stock->at(i)->get_name() << ',';
        outFile << avaliable_stock->at(i)->get_data() << ',';
        outFile << avaliable_stock->at(i)->get_amount() << ',';
        outFile << avaliable_stock->at(i)->get_stock() << '\n';
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