#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(const string &s, const string &t) {
        if (s.size() != t.size()) return false;
        int m[26] = {0};
        for (char i : s) ++m[i - 'a'];
        for (char i : t)
            if (--m[i - 'a'] < 0) return false;
        return true;
    }
};
