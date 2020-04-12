#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        bool flag = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
                continue;
            }
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                flag = !flag;
                for (; i < intervals.size(); i++) res.push_back(intervals[i]);
                break;
            }
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        if (!flag) res.push_back(newInterval);
        return res;
    }
};
