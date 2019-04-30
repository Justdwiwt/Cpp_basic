#include <string>
#include <iostream>
#include <vector>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma clang diagnostic ignored "-Wuninitialized"
using namespace std;

int add(int a, int b) {
    return a + b;
}

vector<int> *max(vector<int> *arr) {
    for (int i = 0; i < arr->size(); ++i) {
        if (arr->begin() < arr->end()) {
            arr->push_back(i);
        }
    }
    return arr;
}

void init() {
    int a, b;
    cin >> a >> b;
    int res = add(a, b);
    vector<int32_t> arr;
    vector<int> *rec;
    max(rec);
    for (int i = 0; i < arr.size(); ++i) {
        arr.push_back(i);
    }
    cout << res << endl;
}

#pragma clang diagnostic pop