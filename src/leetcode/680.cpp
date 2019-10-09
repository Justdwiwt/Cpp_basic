#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() <= 2) return true;
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end])
                return helper(s, start + 1, end) || helper(s, start, end - 1);
            start++;
            end--;
        }
        return true;

    }

    bool helper(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};
