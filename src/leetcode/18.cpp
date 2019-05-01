#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int >> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> vec;
        vector<int> v(4);
        if (nums.size() < 4) return vec;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                auto m = target - nums[i] - nums[j];
                auto l = j + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    auto sum = nums[l] + nums[r];
                    if (m == sum) {
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[l];
                        v[3] = nums[r];
                        vec.push_back(v);
                        ++l;
                        --r;
                        while (l < r && nums[r] == nums[r + 1]) --r;
                        while (l < r && nums[l] == nums[l - 1]) ++l;
                    } else if (m < sum) {
                        --r;
                    } else {
                        ++l;
                    }
                }
                while (j < nums.size() - 2 && nums[j] == nums[j + 1]) ++j;
            }
            while (i < nums.size() - 3 && nums[i] == nums[i + 1]) ++i;
        }
        return vec;
    }
};

