#ifndef STOCK_H
#define STOCK_H

#include "data.h"

class Stock : public Data
{
private:
    int stock;
    int init_stock;
public:
    Stock();
    Stock(string, string, double, int);
    string get_name();
    string get_data();
    double get_amount();
    int get_stock();
    int get_init_stock();
    bool is_init();

    void set_name(string);
    void set_data(string);
    void set_amount(double);
    void set_stock(int);
    void add_stock(int);
    void remove_stock(int);
    void list_data();

    ~Stock();
};

#endif