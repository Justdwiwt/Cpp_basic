#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int light = 0;
        int right = nums.size() - 1;
        while (light < right) {
            int mid = light + (right - light) / 2;
            nums[mid] == nums[mid ^ 1] ? (light = mid + 1) : (right = mid);
        }
        return nums[light];
    }
};
