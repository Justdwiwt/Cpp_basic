#ifndef CPPTESTPROJECT_TOHEX_H
#define CPPTESTPROJECT_TOHEX_H

#include <string>
#include <iostream>

using namespace std;

void toHex() {
    const string hexdigits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 and 15"
         << "separated by spaces. Hit ENTER when finished: "
         << endl;
    string result;
    string::size_type n;
    while (cin >> n)
        if (n < hexdigits.size())
            result += hexdigits[n];
    cout << "Hex number is: "
         << result
         << endl;
}

#endif //CPPTESTPROJECT_TOHEX_H
