#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "data.h"
#include "stock.h"

class User : public Data
{   
private:
    vector<Stock*> *stock; 
public:
    User();
    User(string, string, double);
    User(string, string, double, vector<Stock*>);
    string get_name();
    string get_data();
    double get_amount();

    void set_name(string);
    void set_data(string);
    void set_amount(double);
    void buy_stock(Stock* int);
    void sell_stock(Stock*, int);
    void listdata();

    ~User();
};

#endif