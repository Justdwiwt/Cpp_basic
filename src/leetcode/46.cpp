#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        int s1 = nums.size();
        int result = s1;
        int left = 0;
        int right = s1 - 1;
        int count = 0;
        int *t = &count;
        for (int i = s1 - 1; i > 1; i--) result *= i;
        vector<vector<int>> res(result, nums);
        func(nums, res, left, right, t);
        return res;
    }

private:
    void func(vector<int> &nums, vector<vector<int>> &res, int left, int right, int *t) {
        if (left == right) {
            res[*t] = nums;
            (*t)++;
            return;
        }
        for (int i = left; i <= right; i++) {
            swap(nums[i], nums[left]);
            func(nums, res, left + 1, right, t);
            swap(nums[i], nums[left]);
        }
    }
};
