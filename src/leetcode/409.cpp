#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindrome(const string &s) {
        int res = 0;
        for (char c = 'A'; c <= 'z'; ++c)
            res += count(s.begin(), s.end(), c) & 1;
        return s.size() - max(0, res - 1);
    }
};
