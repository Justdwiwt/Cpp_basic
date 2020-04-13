#include <cassert>

class Solution {
public:
    int mySqrt(int x) {
        assert(x >= 0);
        if (x == 0 || x == 1) return x;
        float tmp = x;
        float half = 0.5f * tmp;
        int i = *(int *) &tmp;
        i = 0x5f375a86 - (i >> 1);
        tmp = *(float *) &i;
        tmp = tmp * (1.5f - half * tmp * tmp);
        tmp = tmp * (1.5f - half * tmp * tmp);
        tmp = tmp * (1.5f - half * tmp * tmp);
        int res = 1 / tmp;
        if (res * res > x) return res - 1;
        return res;
    }
};
