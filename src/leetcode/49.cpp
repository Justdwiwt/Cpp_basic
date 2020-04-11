#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, vector<string>> m;
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        for (auto &e : strs) {
            string tt = e;
            std::sort(e.begin(), e.end());
            m[e].emplace_back(tt);
        }
        for (auto &e : m) res.emplace_back(e.second);
        return res;
    }
};
