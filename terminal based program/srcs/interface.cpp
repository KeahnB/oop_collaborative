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

void Interface::delete_stock()
{
    if (user->get_name() == "N/A") {
        cout << "$You must login as a stock owner to use this command" << endl;
        cout << endl;
        return;
    }
    string stock_name;
    cout << "$Enter stock name you want to add: " << endl;
    cout << "$";
    getline(cin, stock_name);
    int pos = -1;
    for (int i = 0; i < avaliable_stock->size(); i++)
    {
        if (stock_name == avaliable_stock->at(i)->get_name())
        {
            if (!(avaliable_stock->at(i)->get_data() == user->get_name()))
            {
                cout << "$Error: could not delete " << stock_name << endl;
                cout << "$The stock you tried to delete does not belong to you" << endl;
                cout << endl;
                return;
            }
            if (!(avaliable_stock->at(i)->is_init())){
                cout << "$Error: could not delete " << stock_name << endl;
                cout << "$The stock you tried to delete has already been distributed and cannot be deleted" << endl;
                cout << endl;
                return;
            }
            pos = i;  
            break;       
        }
    }
    if (pos = -1) {
        cout << "$" << stock_name << " could not be found in the system" << endl;
        cout << "$To check all avaliable stocks, type:" << endl;
        cout << "$stock view" << endl;
        cout << endl;
        return;
    }
    string check;
    cout << "$Are you sure you want to delete the " << stock_name << " stock" << endl;
    cout << "$Once you delete the stock, it can not be retrieved" << endl;
    cout << "$Enter Yes or No" << endl;
    cout << "$";
    getline(cin, check);
    if (check == "No") {
        cout << "$Deletion of " << stock_name << " canceled" << endl;
        cout << endl;
        return;
    }
    avaliable_stock->erase(avaliable_stock->begin()+pos);
    cout << "$" << stock_name << " has been deleted" << endl;
    cout << endl;
    write_stock();
}

void Interface::create_stock()
{
    if (user->get_name() == "N/A") {
        cout << "$You must login as a user to use this command" << endl;
        cout << endl;
        return;
    }
    string stock_name;
    cout << "$Enter stock name you want to add: " << endl;
    cout << "$";
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
    cout << "$";
    getline(cin, stock_price);
    cout << "$Enter the current number of avaliable stock:" << endl;
    cout << "$";
    getline(cin, stock_amount);
    Stock *stock_obj = new Stock(stock_name, user->get_name(), stod(stock_price), stoi(stock_amount));
    avaliable_stock->push_back(stock_obj);
    write_stock();
}

void Interface::read_stock() {
    ifstream inFile("files/stock.csv");
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

void Interface::write_stock() {
    ofstream outFile;
    outFile.open("files/stock.csv", ios::out | ios::trunc);
    for (int i = 0; i < avaliable_stock->size(); i++)
    {
        outFile << avaliable_stock->at(i)->get_name() << ',';
        outFile << avaliable_stock->at(i)->get_data() << ',';
        outFile << avaliable_stock->at(i)->get_amount() << ',';
        outFile << avaliable_stock->at(i)->get_stock() << '\n';
    }
}

void Interface::read_user()
{
    ifstream inFile("files/" + user->get_name() + ".csv");
    string data;
    vector<string> user_line;
    vector<Stock*> *temp_stock_list;
    bool is_line = true;
    while (getline(inFile, data))
    {
        vector<string> line;
        istringstream ss(data);
        string temp;
        while (getline(ss, temp, ','))
            line.push_back(temp);
        if (is_line) {
            user_line = line;
            is_line = false;
        }
        Stock *stock_obj = new Stock(line.at(0), line.at(1), stod(line.at(2)), stoi(line.at(3)));
        temp_stock_list->push_back(stock_obj);
    }
    User *temp_new_user = new User(user_line.at(0), user_line.at(1), stod(user_line.at(2)), *temp_stock_list);
    delete user;
    user = temp_new_user;
}

void Interface::write_user()
{
    ofstream outFile;
    outFile.open("files/" + user->get_name() + ".csv", ios::out | ios::trunc);
    outFile << user->get_name() + ',';
    outFile << user->get_data() + ',';
    outFile << user->get_amount() + '\n';
    for (int i = 0; i < user->stock->size(); i++)
    {
        outFile << user->stock->at(i)->get_name() << ',';
        outFile << user->stock->at(i)->get_data() << ',';
        outFile << user->stock->at(i)->get_amount() << ',';
        outFile << user->stock->at(i)->get_stock() << '\n';
    }
}

void Interface::buy_stock(string new_stock, int stock_amount)
{
    if (user->get_name() == "N/A") {
        cout << "$You must be logged in to access this command" << endl;
        cout << endl;
        return;
    }
    int pos = -1;
    for (int i = 0; i < avaliable_stock->size(); i++)
        if (avaliable_stock->at(i)->get_name() == new_stock) {pos = i; break;}
    if (!(user->get_amount() >= stock_amount * avaliable_stock->at(pos)->get_amount()))
    {
        cout << "$You do not have enough money to buy " << stock_amount << " of " << new_stock << endl;
        cout << "$To show your amount of money, type:" << endl;
        cout << "$user information" << endl;
        cout << endl;
        return;
    }
    if (!(avaliable_stock->at(pos)->get_stock() >= stock_amount)) {
        cout << "$There is currently not " << stock_amount << " avaliable " << new_stock << " stocks" << endl;
        cout << "$To show the information on " << new_stock << ", type: " << endl;
        cout << "$stock view " << new_stock << endl;
        cout << endl;
        return;
    }
    for (int i = 0; i < user->stock->size(); i++)
        if (new_stock == user->stock->at(i)->get_name()) {
            user->stock->at(i)->add_stock(stock_amount);
            cout << "$" << stock_amount << " " << new_stock << " stock brought successfully" << endl;
            cout << endl;
            return;
        }
    avaliable_stock->at(pos)->remove_stock(stock_amount);
    Stock *stock_obj = new Stock(new_stock, avaliable_stock->at(pos)->get_data(), avaliable_stock->at(pos)->get_amount(), stock_amount);
    user->stock->push_back(stock_obj);
    cout << "$" << stock_amount << " " <<  new_stock << " stock brought successfully" << endl;
    cout << endl;
    write_stock();
    write_user();
    return;
}

void Interface::sell_stock(string new_stock, int stock_amount)
{
    if (user->get_name() == "N/A") {
        cout << "$You must be logged in to access this command" << endl;
        cout << endl;
        return;
    }
    int pos = -1;
    for (int i = 0; i < user->stock->size(); i++)
        if (user->stock->at(i)->get_name() == new_stock) {pos = i; break;}
    if (!(user->stock->at(pos)->get_stock() >= stock_amount)) {
        cout << "$You do not currently own " << stock_amount << " avaliable " << new_stock << " stocks" << endl;
        cout << "$To show the information on your " << new_stock << " stock, type: " << endl;
        cout << "$user stock " << new_stock << endl;
        cout << endl;
        return;
    }
    int stock_pos = 0;
    for (int i = 0; i < avaliable_stock->size(); i++)
        if (new_stock == avaliable_stock->at(i)->get_name()) {stock_pos = i;}
    avaliable_stock->at(stock_pos)->add_stock(stock_amount);
    user->stock->at(pos)->remove_stock(stock_amount);
    user->set_amount((user->get_amount()) * stock_amount);
    if (user->stock->at(pos)->get_stock() == 0) {user->stock->erase(user->stock->begin()+pos);}
    cout << "$" << stock_amount << " " <<  new_stock << " stock sold successfully" << endl;
    cout << endl;
    write_stock();
    write_user();
    return;
}

void Interface::error(vector<string> error) {

}