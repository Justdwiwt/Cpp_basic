#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        unordered_map<char, int> map;
        int pLeft = 0;
        int count = 0;
        int minSize = INT_MAX;
        for (char c:t) ++map[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--map[s[i]] >= 0) ++count;
            while (count == t.size()) {
                if (minSize > i - pLeft + 1) {
                    minSize = i - pLeft + 1;
                    res = s.substr(pLeft, minSize);
                }
                if (++map[s[pLeft]] > 0) --count;
                ++pLeft;
            }
        }
        return res;
    }
};
