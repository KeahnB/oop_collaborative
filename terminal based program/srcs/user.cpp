#include "user.h"

User::User()
{
    name = "N/A";
    data = "N/A";
    amount = 0.0;
    stock = new vector<Stock *>;
    stock->clear();
}

User::User(string new_name, string new_data, double new_amount)
{
    cout << "test user" << endl;
    name = new_name;
    data = new_data;
    amount = new_amount;
    stock = new vector<Stock *>;
    stock->clear();
}

void User::list_data(string compair_name)
{
    for (int i = 0; i < stock->size(); i++)
    {
        if (stock->at(i)->get_name() == compair_name)
        {
            cout << "$Stock Name: " << stock->at(i)->get_name() << endl;
            cout << "$Stock Producer: " << stock->at(i)->get_data() << endl;
            cout << "$Stock Price in AUD: $" << stock->at(i)->get_amount() << endl;
            cout << "$Amount you own: " << stock->at(i)->get_stock() << endl;
            cout << endl;
            return;
        }
    }
    cout << "$Sorry, but it seems that you don't own any of this stock." << endl;
    cout << "$To get more information on the specific stock, type:" << endl;
    cout << endl;
    cout << "$user stock [stock name]" << endl;
    cout << endl;
}

void User::list_data()
{
    for (int i = 0; i < stock->size(); i++)
    {
        cout << "$Stock Name: " << stock->at(i)->get_name() << endl;
        cout << "$Stock Producer: " << stock->at(i)->get_data() << endl;
        cout << "$Stock Price in AUD: $" << stock->at(i)->get_amount() << endl;
        cout << "$Amount you own: " << stock->at(i)->get_stock() << endl;
        cout << endl;
    }
}

string User::get_name() { return name; }
string User::get_data() { return data; }
double User::get_amount() { return amount; }

void User::set_name(string new_name) { name = new_name; }
void User::set_data(string new_data) { data = new_data; }
void User::set_amount(double new_amount) { amount = new_amount; }
User::~User() {};