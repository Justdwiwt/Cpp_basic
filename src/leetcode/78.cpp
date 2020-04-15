#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            int size = res.size();
            for (int j = 0; j < size; ++j) {
                res.push_back(res[j]);
                res.back().push_back(num);
            }
        }
        return res;
    }
};
