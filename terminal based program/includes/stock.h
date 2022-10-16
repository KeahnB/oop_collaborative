#ifndef STOCK_H
#define STOCK_H

#include "data.h"

class Stock : public Data
{
private:
    int stock;

public:
    Stock();
    Stock(string, string, double, int);
    string get_name();
    string get_data();
    double get_amount();
    int get_stock();

    void set_name(string);
    void set_data(string);
    void set_amount(double);
    void set_stock(int);

    ~Stock();
};

#endif