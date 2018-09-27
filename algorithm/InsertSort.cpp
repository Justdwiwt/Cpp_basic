#include <iostream>
#include <vector>

using namespace std;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

void InsertSort(int arr[], int n) {
    for (int i = 1; i <= n; ++i)
        for (int j = i; j > 0; --j)
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
}

void insertion_sort(vector<int> &v) {
    int temp = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1] > v[i]) {
            temp = v[i];
            for (int j = i - 1; j >= 0 && v[j] > temp; j--)
                v[j + 1] = v[j];
            v[i + 1] = temp;
        }
    }
}

#pragma clang diagnostic pop