#include <climits>

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        long a[100];
        int i = 0;
        while (x != 0) {
            a[i] = x % 10;
            x /= 10;
            i++;
        }
        for (int j = i - 1, k = 1; j >= 0; j--) {
            res += a[j] * k;
            if (res > INT_MAX || res < INT_MIN) return 0;
            k *= 10;
        }
        return res;
    }
};
