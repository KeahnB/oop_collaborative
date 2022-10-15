#include "data.h"

Data::Data(string new_name, string new_data, double new_amount)
{
    name = new_name;
    data = new_data;
    amount = new_amount;
}

Data::~Data(){};