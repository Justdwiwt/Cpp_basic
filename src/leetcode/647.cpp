#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        if (s.empty()) {
            return res;
        }
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            helper(s, i, i, res);
            helper(s, i, i + 1, res);
        }
        return res;
    }

    void helper(string s, int i, int j, int &res) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
            ++res;
        }
    }
};
