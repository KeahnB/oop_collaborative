#include "stock.h"

Stock::Stock()
{
    name = "N/A";
    data = "N/A";
    amount = 0.0;
    stock = 0;
}

Stock::Stock(string new_name, string new_data, double new_amount, int new_stock)
{
    name = new_name;
    data = new_data;
    amount = new_amount;
    stock = new_stock;
}

string Stock::get_name() { return name; }
string Stock::get_data() { return data; }
double Stock::get_amount() { return amount; }
int Stock::get_stock() { return stock; }

void Stock::set_name(string new_name) { name = new_name; }
void Stock::set_data(string new_data) { data = new_data; }
void Stock::set_amount(double new_amount) { amount = new_amount; }
void Stock::set_stock(int new_stock) { stock = new_stock; }

Stock::~Stock() {}
