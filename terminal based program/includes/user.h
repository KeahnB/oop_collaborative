#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "data.h"
#include "stock.h"

class User : public Data
{
public:
    vector<Stock *> *stock;
    User();
    User(string, string, double);
    string get_name();
    string get_data();
    double get_amount();

    void set_name(string);
    void set_data(string);
    void set_amount(double);
    void list_data();
    void list_data(string);

    ~User();
};

#endif