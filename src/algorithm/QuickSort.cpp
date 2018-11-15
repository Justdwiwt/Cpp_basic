#include <iostream>

int OnceSort(int arr[], int first, int end);

void QuickSort(int arr[], int first, int end) {
    if (first < end) {
        int pivot = OnceSort(arr, first, end);
        //已经有轴值了，再对轴值左右进行递归
        QuickSort(arr, first, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

int OnceSort(int arr[], int first, int end) {
    int i = first, j = end;
    //当i<j即移动的点还没到中间时循环
    while (i < j) {
        //右边区开始，保证i<j并且arr[i]小于或者等于arr[j]的时候就向左遍历
        while (i < j && arr[i] <= arr[j]) --j;
        //这时候已经跳出循环，说明j>i 或者 arr[i]大于arr[j]了，如果i<j那就是arr[i]大于arr[j]，那就交换
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        //对另一边执行同样的操作
        while (i < j && arr[i] <= arr[j]) ++i;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //返回已经移动的一边当做下次排序的轴值
    return i;
}