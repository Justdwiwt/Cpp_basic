#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[0] <= nums[mid]) l = mid + 1;
            else r = mid;
        }
        return nums[0] < nums[l] ? nums[0] : nums[l];
    }
};
