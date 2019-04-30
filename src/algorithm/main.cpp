#include <iostream>
#include "Sales_data.h"
#include "../basic/ToHex.h"

#define _outMax(x, y) ({typeof(x) _max1 = (x); typeof(y) _max2 = (y); (void)(&_max1 == &_max2); _max1 > _max2 ? _max1 : _max2;})

using namespace std;

int salesData();

int main() {
    toHex();
    salesData();
    return 0;
}

int salesData() {
    Sales_data data1, data2;
    double price = 0;
    int a = 5;
    int b = 3;
    cout << _outMax(a, b);
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " << totalCnt
             << " " << totalRevenue << " ";
        if (totalCnt != 0)
            cout << totalRevenue / totalCnt << endl;
        else
            cout << "(no sales)" << endl;
        return 0;
    } else {
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }
}