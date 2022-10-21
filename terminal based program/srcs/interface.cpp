#include "interface.h"

Interface::Interface() {}
// Sets pointer to user that will be used
Interface::Interface(User *user) : user(user) {}

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

//Runs when app is initiated
void Interface::start()
{
    cout << "Welcome to Sneed's stock exchange" << endl;
    cout << "For help, type: help" << endl;
    cout << endl;
}

//Displays help screen when help command is typed
void Interface::help()
{
    cout << endl;
    cout << "List of commands:" << endl;
    cout << "Login to user:" << endl;
    cout << "login" << endl;
    cout << "Create new user:" << endl;
    cout << "sign-up" << endl;
    cout << "Logout of user:" << endl;
    cout << "logout" << endl;
    cout << "Delete user:" << endl;
    cout << "user \"delete\"" << endl;
    cout << "Command to buy stock:" << endl;
    cout << "buy \"stock name\" \"amount to buy\"" << endl;
    cout << "Command to sell stock:" << endl;
    cout << "sell \"stock name\" \"amount to sell\"" << endl;
    cout << "Command to view specific avaliable stock:" << endl;
    cout << "stock view \"stock name\"" << endl;
    cout << "Command to view all avaliable stock:" << endl;
    cout << "stock view" << endl;
    cout << "Command to view specific user stock:" << endl;
    cout << "user stock \"stock name\"" << endl;
    cout << "Command to view all user stock:" << endl;
    cout << "user stock" << endl;
    cout << "Command to delete stock:" << endl;
    cout << "stock delete" << endl;
    cout << "Command to create stock: " << endl;
    cout << "stock create" << endl;
    cout << "Command to exit application:" << endl;
    cout << "exit" << endl;
    cout << endl;
}

//Gets called when user inputs a command
bool Interface::commandProcess(vector<string> commands)
{
    //checks if command is empty
    if (commands.size() == 0)
    {
        return 1;
    }
    //checks if command is based on the user
    if (commands.at(0) == "user")
    {
        user_command(commands);
        return 1;
    }
    //checks if command is to login to user
    if (commands.at(0) == "login")
    {
        login();
        return 1;
    }
    //checks if command is to sell stock from the user
    if (commands.at(0) == "sell")
    {
        //checks whether formating of command is correct
        if (!(commands.size() == 3))
        {
            cout << "Error: incorrect formating" << endl;
            cout << "To sell stock, type:" << endl;
            cout << "sell \"stock name\" \"amount to sell\"" << endl;
            cout << endl;
            return 1;
        }
        //runs sell stock function
        sell_stock(commands.at(1), stoi(commands.at(2)));
        return 1;
    }
    //checks if command is to buy stock
    if (commands.at(0) == "buy")
    {
        //checks if formating of command is correct
        if (!(commands.size() == 3))
        {
            cout << "Error: incorrect formating" << endl;
            cout << "To buy stock, type:" << endl;
            cout << "buy \"stock name\" \"amount to sell\"" << endl;
            cout << endl;
            return 1;
        }
        //runs sell stock function
        buy_stock(commands.at(1), stoi(commands.at(2)));
        return 1;
    }
    //runs the logout function to logout the user
    if (commands.at(0) == "logout")
    {
        logout();
        return 1;
    }
    //calls the create new user function
    if (commands.at(0) == "sign-up")
    {
        create_user();
        return 1;
    }
    //checks if command is based on the stock commands
    if (commands.at(0) == "stock")
    {
        stock_command(commands);
        return 1;
    }
    //displays help menu
    if (commands.at(0) == "help")
    {
        help();
        return 1;
    }
    //exits out of application
    if (commands.at(0) == "exit")
    {
        return 0;
    }
    //shows warning to ser that command was not valid
    cout << commands.at(0) << " is not valid command." << endl;
    cout << "Please refer to the \"help\" for a list of avaliable commands" << endl;
    cout << endl;
    return 1;
}

//gets called when command is user based
void Interface::user_command(vector<string> commands)
{
    cout << endl;
    //checks if there is anymore commands that the user inputed
    if (commands.size() == 1)
    {
        //if user didnt input enough commands, it tells them how to use the commands
        cout << "Error: Incorrect command input" << endl;
        cout << "To show user commands type: \"help\"" << endl;
        cout << endl;
        return;
    }
    //checks if num of commands is 3
    if (commands.size() == 3)
    {
        //checks if second command is stock
        if (commands.at(1) == "stock")
        {
            //goes through all user stocks until specific stock has been found
            for (int i = 0; i < user->stock->size(); i++)
            {
                if (user->stock->at(i)->get_name() == commands.at(2))
                {
                    //calls the list data function from the user
                    user->list_data(user->stock->at(i)->get_name());
                    return;
                }
            }
            //displays if user did not own any of the stock to display
            cout << "You do not own any of this stock" << endl;
            cout << "To show your owned stock type:" << endl;
            cout << "user stock" << endl;
            cout << endl;
        }
    }
    //checks if command amount is 2
    if (commands.size() == 2)
    {
        //checks if second command is stock
        if (commands.at(1) == "stock")
        {
            //lists all user stock data
            user->list_data();
            return;
        }
        //checks if seocnd command is delete
        if (commands.at(1) == "delete")
        {
            //calls delete user function
            delete_user();
            return;
        }
        //checks if second command is information
        if (commands.at(1) == "information")
        {
            //checks if user has been signed in
            if (user->get_name() == "N/A")
            {
                cout << "You must be logged into use this command" << endl;
                cout << endl;
                return;
            }
            //displays user information
            cout << "Username: " << user->get_name() << endl;
            cout << "Password: " << user->get_data() << endl;
            cout << "Money: " << user->get_amount() << endl;
            return;
        }
    }
    //tells user that command input was incorrect
    cout << "Command input was incorrect" << endl;
    cout << "For information on commands, type: \"help\"" << endl;
    cout << endl;
}

//runs through different stock commands
void Interface::stock_command(vector<string> commands)
{
    cout << endl;
    if (commands.size() == 1)
    {
        cout << "Error: Incorrect command input" << endl;
        cout << "To show user commands type: \"help\"" << endl;
        cout << endl;
        return;
    }
    if (commands.size() == 3)
    {
        if (commands.at(1) == "view")
        {
            list_data(commands.at(2));
            return;
        }
    }
    if (commands.size() == 2)
    {
        if (commands.at(1) == "view")
        {
            list_data();
            return;
        }
        if (commands.at(1) == "create")
        {
            create_stock();
            return;
        }
        if (commands.at(1) == "delete")
        {
            delete_stock();
            return;
        }
    }
    cout << "Command input was incorrect" << endl;
    cout << "For information on commands, type: \"help\"" << endl;
    cout << endl;
}

//lists all avaliable stock data
void Interface::list_data()
{
    for (int i = 0; i < avaliable_stock.size(); i++)
    {
        cout << "Stock name: " << avaliable_stock.at(i)->get_name() << endl;
        cout << "Stock owner: " << avaliable_stock.at(i)->get_data() << endl;
        cout << "Stock price: " << avaliable_stock.at(i)->get_amount() << endl;
        cout << "Stock amount: " << avaliable_stock.at(i)->get_stock() << endl;
        cout << endl;
    }
}

//lists specific avaliable stock information
void Interface::list_data(string _name)
{
    for (int i = 0; i < avaliable_stock.size(); i++)
    {
        if (avaliable_stock.at(i)->get_name() == _name)
        {
            cout << "Stock name: " << avaliable_stock.at(i)->get_name() << endl;
            cout << "Stock owner: " << avaliable_stock.at(i)->get_data() << endl;
            cout << "Stock price: " << avaliable_stock.at(i)->get_amount() << endl;
            cout << "Stock amount: " << avaliable_stock.at(i)->get_stock() << endl;
            cout << endl;
            return;
        }
    }
    cout << "This stock does not exist" << endl;
    cout << "To show the avaliable stock, type:" << endl;
    cout << "stock view" << endl;
    cout << endl;
}

//logs in the user if username exist and password is correct
void Interface::login()
{
    if (!(user->get_name() == "N/A"))
    {
        cout << endl;
        cout << "You must logout in order to login to a new account" << endl;
        cout << endl;
        return;
    }
    cout << "Enter your username: " << endl;
    cout << "$ ";
    string input;
    getline(cin, input);
    cout << endl;
    user->set_name(input);
    ifstream inFile("files/" + input + ".csv");
    if (!inFile.good())
    {
        cout << "Error: The user " << input << " was not found" << endl;
        cout << endl;
        return;
    }
    read_user();
    cout << "Enter your password: " << endl;
    cout << "$ ";
    getline(cin, input);
    cout << endl;
    if (!(user->get_data() == input))
    {
        cout << "Your password was incorrect" << endl;
        cout << endl;
        user->set_name("default");
        read_user();
        return;
    }
    cout << "Success" << endl;
    cout << "You are now logged in as " << user->get_name();
    cout << endl;
}

//Creates a user csv that stores the user information
void Interface::create_user()
{
    if (!(user->get_name() == "N/A"))
    {
        cout << endl;
        cout << "You must logout in order to create to a new account" << endl;
        cout << endl;
        return;
    }
    cout << "Enter new username: " << endl;
    cout << "$ ";
    string username;
    getline(cin, username);
    cout << endl;
    ifstream inFile("files/" + username + ".csv");
    if (inFile.good())
    {
        cout << "Error: The user " << username << " already exists" << endl;
        cout << endl;
        return;
    }
    cout << "Enter password: " << endl;
    cout << "$ ";
    string input;
    getline(cin, input);
    cout << endl;
    cout << "Enter amount of money you want to put in: " << endl;
    cout << "$ ";
    string money_str;
    getline(cin, money_str);
    cout << endl;
    cout << "test1" << endl;
    User *user_obj = new User(username, input, stod(money_str));
    cout << "test2" << endl;
    user = user_obj;
    write_user();
    cout << "Success" << endl;
    cout << "You are now signed in as " << user->get_name();
    cout << endl;
}

//Logs the user out and reinitializes the default user class
void Interface::logout()
{
    cout << endl;
    cout << "You have been logged out of " << user->get_name() << endl;
    cout << endl;
    user->set_name("default");
    read_user();
}

//Deletes the user csv
void Interface::delete_user()
{
    if (!(user->get_name() == "N/A"))
    {
        cout << endl;
        cout << "You must be logged in to the user account to delete it" << endl;
        cout << endl;
        return;
    }
    if (!(user->stock->size() == 0))
    {
        cout << endl;
        cout << "All your stocks must be sold before deleting the account" << endl;
        cout << endl;
        return;
    }
    cout << endl;
    cout << "Are you sure you want to delete this user" << endl;
    cout << "Once you delete the user, it can not be retrieved" << endl;
    cout << "Enter Yes or No" << endl;
    cout << "$ ";
    string check;
    getline(cin, check);
    if (check == "No")
    {
        cout << "Deletion of " << user->get_name() << " canceled" << endl;
        cout << endl;
        return;
    }
    cout << user->get_name() << " has been deleted" << endl;
    cout << endl;
    remove(("files/" + user->get_name() + ".csv").c_str());
    user->set_name("default");
    read_user();
}

//Deletes the stock from the stock csv
void Interface::delete_stock()
{
    if (user->get_name() == "N/A")
    {
        cout << "$You must login as a stock owner to use this command" << endl;
        cout << endl;
        return;
    }
    string stock_name;
    cout << "Enter stock name you want to delete: " << endl;
    cout << "$ ";
    getline(cin, stock_name);
    int pos = -1;
    for (int i = 0; i < avaliable_stock.size(); i++)
    {
        if (stock_name == avaliable_stock.at(i)->get_name())
        {
            if (!(avaliable_stock.at(i)->get_data() == user->get_name()))
            {
                cout << "Error: could not delete " << stock_name << endl;
                cout << "The stock you tried to delete does not belong to you" << endl;
                cout << endl;
                return;
            }
            if (!(avaliable_stock.at(i)->is_init()))
            {
                cout << "Error: could not delete " << stock_name << endl;
                cout << "The stock you tried to delete has already been distributed and cannot be deleted" << endl;
                cout << endl;
                return;
            }
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << stock_name << " could not be found in the system" << endl;
        cout << "To check all avaliable stocks, type:" << endl;
        cout << "stock view" << endl;
        cout << endl;
        return;
    }
    string check;
    cout << "Are you sure you want to delete the " << stock_name << " stock" << endl;
    cout << "Once you delete the stock, it can not be retrieved" << endl;
    cout << "Enter Yes or No" << endl;
    cout << "$ ";
    getline(cin, check);
    if (check == "No")
    {
        cout << "Deletion of " << stock_name << " canceled" << endl;
        cout << endl;
        return;
    }
    avaliable_stock.erase(avaliable_stock.begin() + pos);
    cout << stock_name << " has been deleted" << endl;
    cout << endl;
    write_stock();
}

//Creates new stock
void Interface::create_stock()
{
    if (user->get_name() == "N/A")
    {
        cout << "You must login as a user to use this command" << endl;
        cout << endl;
        return;
    }
    string stock_name;
    cout << "Enter stock name you want to add: " << endl;
    cout << "$ ";
    getline(cin, stock_name);
    for (int i = 0; i < avaliable_stock.size(); i++)
    {
        if (stock_name == avaliable_stock.at(i)->get_name())
        {
            cout << "The stock you tried to create already exists in the system" << endl;
            cout << "Please choose a different name for the stock" << endl;
            cout << endl;
            return;
        }
    }
    cout << "Enter the current pricing of the stock:" << endl;
    string stock_price, stock_amount;
    cout << "$ ";
    getline(cin, stock_price);
    cout << "Enter the current number of avaliable stock:" << endl;
    cout << "$ ";
    getline(cin, stock_amount);
    Stock *stock_obj = new Stock(stock_name, user->get_name(), stod(stock_price), stoi(stock_amount));
    avaliable_stock.push_back(stock_obj);
    write_stock();
}

//Reads in the information from the stock csv and stores it in the avaliable stock vector of objects
void Interface::read_stock()
{
    ifstream inFile("files/stock.csv");
    string data;
    while (getline(inFile, data))
    {
        vector<string> line;
        istringstream ss(data);
        string temp;
        while (getline(ss, temp, ','))
            line.push_back(temp);
        avaliable_stock.push_back(new Stock(line.at(0), line.at(1), stod(line.at(2)), stoi(line.at(3))));
    }
}

//Writes the data from the stock array to the stock csv
void Interface::write_stock()
{
    ofstream outFile;
    outFile.open("files/stock.csv", ios::out | ios::trunc);
    for (int i = 0; i < avaliable_stock.size(); i++)
    {
        outFile << avaliable_stock.at(i)->get_name() << ',';
        outFile << avaliable_stock.at(i)->get_data() << ',';
        outFile << avaliable_stock.at(i)->get_amount() << ',';
        outFile << avaliable_stock.at(i)->get_stock() << '\n';
    }
}

//reads a specific user csv file and adds all its data to the user object
void Interface::read_user()
{
    cout << user->get_name() << endl;
    ifstream inFile("files/" + user->get_name() + ".csv");
    string data;
    string user_temp;
    vector<string> user_line;
    getline(inFile, data);
    istringstream t_ss(data);
    while (getline(t_ss, user_temp, ','))
        user_line.push_back(user_temp);
    user->set_name(user_line.at(0));
    user->set_data(user_line.at(1));
    user->set_amount(stod(user_line.at(2)));
    user->stock->clear();
    while (getline(inFile, data))
    {
        vector<string> line;
        istringstream ss(data);
        string temp;
        while (getline(ss, temp, ','))
            line.push_back(temp);
        Stock *stock_obj = new Stock(line.at(0), line.at(1), stod(line.at(2)), stoi(line.at(3)));
        user->stock->push_back(stock_obj);
    }
}

//writes all the data the current user has to the current user csv
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

//buys the specified stock if the user has enough money
void Interface::buy_stock(string new_stock, int stock_amount)
{
    if (user->get_name() == "N/A")
    {
        cout << "You must be logged in to access this command" << endl;
        cout << endl;
        return;
    }
    int pos = -1;
    for (int i = 0; i < avaliable_stock.size(); i++)
        if (avaliable_stock.at(i)->get_name() == new_stock)
        {
            pos = i;
            break;
        }
    if (!(user->get_amount() >= stock_amount * avaliable_stock.at(pos)->get_amount()))
    {
        cout << "You do not have enough money to buy " << stock_amount << " of " << new_stock << endl;
        cout << "To show your amount of money, type:" << endl;
        cout << "user information" << endl;
        cout << endl;
        return;
    }
    if (!(avaliable_stock.at(pos)->get_stock() >= stock_amount))
    {
        cout << "There is currently not " << stock_amount << " avaliable " << new_stock << " stocks" << endl;
        cout << "To show the information on " << new_stock << ", type: " << endl;
        cout << "stock view " << new_stock << endl;
        cout << endl;
        return;
    }
    for (int i = 0; i < user->stock->size(); i++)
        if (new_stock == user->stock->at(i)->get_name())
        {
            user->stock->at(i)->add_stock(stock_amount);
            cout << stock_amount << " " << new_stock << " stock brought successfully" << endl;
            cout << endl;
            return;
        }
    avaliable_stock.at(pos)->remove_stock(stock_amount);
    Stock *stock_obj = new Stock(new_stock, avaliable_stock.at(pos)->get_data(), avaliable_stock.at(pos)->get_amount(), stock_amount);
    user->stock->push_back(stock_obj);
    cout << stock_amount << " " << new_stock << " stock brought successfully" << endl;
    cout << endl;
    write_stock();
    write_user();
    return;
}

//Sells user stock if user has enough stock
void Interface::sell_stock(string new_stock, int stock_amount)
{
    if (user->get_name() == "N/A")
    {
        cout << "You must be logged in to access this command" << endl;
        cout << endl;
        return;
    }
    int pos = -1;
    for (int i = 0; i < user->stock->size(); i++)
        if (user->stock->at(i)->get_name() == new_stock)
        {
            pos = i;
            break;
        }
    if (!(user->stock->at(pos)->get_stock() >= stock_amount))
    {
        cout << "You do not currently own " << stock_amount << " avaliable " << new_stock << " stocks" << endl;
        cout << "To show the information on your " << new_stock << " stock, type: " << endl;
        cout << "user stock " << new_stock << endl;
        cout << endl;
        return;
    }
    int stock_pos = 0;
    for (int i = 0; i < avaliable_stock.size(); i++)
        if (new_stock == avaliable_stock.at(i)->get_name())
        {
            stock_pos = i;
        }
    avaliable_stock.at(stock_pos)->add_stock(stock_amount);
    user->stock->at(pos)->remove_stock(stock_amount);
    user->set_amount((user->get_amount()) * stock_amount);
    if (user->stock->at(pos)->get_stock() == 0)
    {
        user->stock->erase(user->stock->begin() + pos);
    }
    cout << stock_amount << " " << new_stock << " stock sold successfully" << endl;
    cout << endl;
    write_stock();
    write_user();
    return;
}
