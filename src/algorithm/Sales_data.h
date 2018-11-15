#ifndef CPPTESTPROJECT_SALES_DATA_H
#define CPPTESTPROJECT_SALES_DATA_H

#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif //CPPTESTPROJECT_SALES_DATA_H
