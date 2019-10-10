#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans{intervals[0]};
        for (auto &interval : intervals) {
            if (ans.back()[1] >= interval[0]) {
                ans.back()[1] = max(interval[1], ans.back()[1]);
                continue;
            } else {
                ans.push_back(interval);
                continue;
            }
        }
        return ans;
    }
};
