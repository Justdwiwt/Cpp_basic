#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> res;
        unordered_map<int, int> map;
        for (auto i:nums) map[i]++;
        vector<pair<int, int>> temp(map.begin(), map.end());
        sort(temp.begin(), temp.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        });
        auto t = temp.begin();
        while (k--) {
            res.push_back(t->first);
            t++;
        }
        return res;
    }
};
