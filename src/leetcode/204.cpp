class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 2; i < n; ++i)
            if (isPrimes(i)) cnt++;
        return cnt;
    }

    static bool isPrimes(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }
};
