#include "data.h"

Data::Data() {
    name = "N/A";
    data = "N/A";
    amount = 0;
}

Data::Data(string new_name, string new_data, double new_amount)
{
    name = new_name;
    data = new_data;
    amount = new_amount;
}

Data::~Data(){};