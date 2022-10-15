#ifndef USER_H
#define USER_H

#include <iostream>
#include "data.h"
using namespace std;

class User : public Data
{
    string get_name();
    string get_data();
    double get_amount();

    void set_name(string);
    void set_data(string);
    void set_amount(double);

    void create(string, string , double);
};

#endif