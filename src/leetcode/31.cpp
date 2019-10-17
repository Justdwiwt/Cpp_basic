#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() > 1) {
            int i;
            for (i = nums.size() - 1; i > 0 && nums[i - 1] >= nums[i]; i--);
            reverse(nums.begin() + i, nums.end());
            if (i-- != 0) {
                auto it = upper_bound(nums.begin() + i, nums.end(), nums[i]);
                swap(nums[i], *it);
            }
        }
    }
};
