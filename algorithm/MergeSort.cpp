#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

void Merge(int arr[], int reg[], int start, int end) {
    if (start >= end) return;
    int len = end - start, mid = (len >> 1) + start;

    //分成两部分
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    //然后合并
    Merge(arr, reg, start1, end1);
    Merge(arr, reg, start2, end2);


    int k = start;
    //两个序列一一比较,哪的序列的元素小就放进reg序列里面,然后位置+1再与另一个序列原来位置的元素比较
    //如此反复,可以把两个有序的序列合并成一个有序的序列
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];

    //然后这里是分情况,如果arr2序列的已经全部都放进reg序列了然后跳出了循环
    //那就表示arr序列还有更大的元素(一个或多个)没有放进reg序列,所以这一步就是接着放
    while (start1 <= end1)
        reg[k++] = arr[start1++];

    //这一步和上面一样
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    //把已经有序的reg序列放回arr序列中
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

void MergeSort(int arr[], const int len) {
    //创建一个同样长度的序列,用于临时存放
    int reg[len];
    Merge(arr, reg, 0, len - 1);
}

#pragma clang diagnostic pop

