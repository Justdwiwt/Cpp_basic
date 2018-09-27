#include <iostream>

// 直接插入排序

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

void InsertSort3(int arr[], int len) {
    int i, j;
    int temp;
    for (i = 1; i < len; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}

void InsertSort2(int arr[], int n) {
    for (int i = 1; i <= n; ++i)
        for (int j = i; j > 0; --j)
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
}


#pragma clang diagnostic pop