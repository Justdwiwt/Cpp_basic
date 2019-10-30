#include <vector>

using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        int res = 0;
        int k = 31;
        int pre = 0;
        vector<int> f(32, 0);
        f[0] = 1;
        f[1] = 2;
        for (auto i = 2; i < 31; ++i)
            f[i] = f[i - 2] + f[i - 1];
        while (k >= 0) {
            if (num & (1 << k)) {
                res += f[k];
                if (pre) return res;
                pre = 1;
            } else pre = 0;
            --k;
        }
        return res + 1;
    }
};
