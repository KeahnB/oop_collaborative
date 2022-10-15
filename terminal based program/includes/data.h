#ifndef DATA_H
#define DATA_H

#include <iostream>
#include "listdata.h"
using namespace std;

class Data : public Listdata
{
protected:
    string name;   // name of user or stock owner
    string data;   // user password or stock name
    double amount; // users money or price of stock
public:
    // virtual get functions to obtain variable values
    virtual string get_name() = 0;
    virtual string get_data() = 0;
    virtual double get_amount() = 0;
    // virtual set functions to change variable values
    virtual void set_name(string) = 0;
    virtual void set_data(string) = 0;
    virtual void set_amount(double) = 0;
    
    Data();
    Data(string, string, double);

    virtual ~Data();
};

#endif