class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        while (n--) {
            b += a;
            a = b - a;
        }
        return a;
    }
};
