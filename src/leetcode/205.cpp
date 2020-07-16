#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.empty() && t.empty()) return true;
        for (int i = 0; i <= s.size() - 1; ++i)
            if (s.find(s[i]) != t.find(t[i])) return false;
        return true;
    }
};
