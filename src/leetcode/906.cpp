#include <string>

using namespace std;

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        int res = 0;
        long left = stol(L), right = stol(R);
        func("", left, right, res);
        for (auto c = '0'; c <= '9'; ++c)
            func(string(1, c), left, right, res);
        return res;
    }

private:
    void func(string cur, long &left, long &right, int &res) {
        if (cur.size() > 9) return;
        if (!cur.empty() && cur[0] != '0') {
            long num = stol(cur);
            num *= num;
            if (num > right) return;
            if (num >= left && isPalindrome(to_string(num))) ++res;
        }
        for (auto c = '0'; c <= '9'; ++c)
            func(string(1, c) + cur + string(1, c), left, right, res);
    }

    bool isPalindrome(string str) {
        int left = 0, right = (int) str.size() - 1;
        while (left < right)
            if (str[left++] != str[right--]) return false;
        return true;
    }
};
