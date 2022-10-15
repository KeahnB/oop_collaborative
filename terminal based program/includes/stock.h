#ifndef STOCK_H
#define STOCK_H

#include "data.h"

class Stock : public Data {
private:
    int stock;
public:
    Stock(string, string, double, int);
    string get_name();
    string get_data();
    double get_amount();
    int get_stock();
    
    void set_name();
    void set_data();
    void set_amount();
    void set_stock();
};

#endif