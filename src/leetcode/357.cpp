class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10;
        int cnt = 9;
        for (auto i = 2; i <= n; ++i) {
            cnt *= (11 - i);
            res += cnt;
        }
        return res;
    }
};
