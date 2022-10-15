#include "user.h"


User::User()
{
    name = "N/A";
    data = "N/A";
    amount = 0;
    stock = new vector<Stock*>;
    stock->clear();
}

User::User(string new_name, string new_data, double new_amount)
{
    name = new_name;
    data = new_data;
    amount = new_amount;
    stock = new vector<Stock*>;
    stock->clear();
}

User::User(string new_name, string new_data, double new_amount, vector<Stock*> new_stock) {
    name = new_name;
    data = new_data;
    amount = new_amount;
    *stock = new_stock;
}

void buy_stock(Stock* new_stock, int stock_amount) {

}

void sell_stock(Stock* new_stock, int stock_amount) {

}

void listdata(Stock* stock_type) {

}

void listdata() {

}

string User::get_name() {return name;}
string User::get_data() {return data;}
double User::get_amount() {return amount;}

void User::set_name(string new_name) {name = new_name;}
void User::set_data(string new_data) {data = new_data;}
void User::set_amount(double new_amount) {amount = new_amount;}


