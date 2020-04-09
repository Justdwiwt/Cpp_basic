#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int res = 0;
        for (int i = 0; i < nums.size() - res; ++i)
            if (nums[i] == val) {
                res++;
                nums[i] = nums[nums.size() - res];
                i--;
            }
        return nums.size() - res;
    }
};
