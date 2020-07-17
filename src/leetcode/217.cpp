#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i)
            for (int j = i - 1; j >= 0; --j)
                if (nums[i] > nums[j]) break;
                else if (nums[i] == nums[j]) return true;
        return false;
    }
};
