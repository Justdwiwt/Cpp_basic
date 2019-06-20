#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0;
        int n = s.size();
        unordered_map<char, int> map;
        for (auto i = 0; i < n; ++i) {
            left = max(left, map[s[i]]);
            map[s[i]] = i + 1;
            res = max(res, i - left + 1);
        }
        return res;
    }
};
