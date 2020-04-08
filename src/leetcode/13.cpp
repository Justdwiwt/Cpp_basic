#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dic = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int res = dic[s.back()];
        for (int i = s.length() - 2; i >= 0; --i)
            res += (dic[s[i]] < dic[s[i + 1]] ? -dic[s[i]] : dic[s[i]]);
        return res;
    }
};
