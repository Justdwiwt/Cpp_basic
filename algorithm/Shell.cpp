#include <vector>

using namespace std;

void ShellInsert(vector<int> &v, int step) {
    int temp = 0;
    for (int i = step; i < v.size(); i++) {
        if (v[i] < v[i - step]) {
            temp = v[i];
            for (int j = i - step; j >= 0 && v[j] > temp; j = j - step)
                v[j + 1] = v[j];
            v[i + 1] = temp;
        }
    }
}

//最终排序
void ShellSort(vector<int> v, vector<int> step) {
    //按增量数组step依次对序列做希尔排序
    for (int i : step)
        ShellInsert(v, i);
}

