#include <algorithm>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long k = i * 10;
            res += (n / k) * i + min(max(n % k - i + 1, 0LL), i);
        }
        return res;
    }
};
