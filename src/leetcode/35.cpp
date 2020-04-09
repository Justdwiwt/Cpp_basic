#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        auto res = find(nums.begin(), nums.end(), target);
        if (res != nums.end()) return res - nums.begin();
        else {
            nums.push_back(target);
            sort(nums.begin(), nums.end());
            auto res = find(nums.begin(), nums.end(), target);
            return res - nums.begin();
        }
    }
};
