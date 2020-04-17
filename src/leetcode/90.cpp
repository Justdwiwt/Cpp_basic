#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        __subsetsWithDup(nums, 0, tmp);
        return res;
    }

private:
    void __subsetsWithDup(vector<int> &nums, int start, vector<int> &tmp) {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i - 1] == nums[i]) continue;
            tmp.push_back(nums[i]);
            __subsetsWithDup(nums, i + 1, tmp);
            tmp.pop_back();
        }
    }
};
