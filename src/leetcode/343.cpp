#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        vector<int> tmp(n + 1);
        tmp[1] = 1;
        tmp[2] = 2;
        tmp[3] = 3;
        for (int i = 3; i <= n; i++) {
            int max = 1;
            for (int j = 1; j < i; j++) {
                if (tmp[j] * tmp[i - j] > max)
                    max = tmp[j] * tmp[i - j];
                if (j * tmp[i - j] > max)
                    max = j * tmp[i - j];
                if (j * (i - j) > max)
                    max = j * (i - j);
            }
            tmp[i] = max;
        }
        return tmp[n];
    }
};