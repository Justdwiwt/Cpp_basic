#include <vector>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        for (auto i = 0; i < nums.size(); ++i) {
            int sum = nums[i];
            for (auto j = i + 1; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) return true;
                if (k != 0 && sum % k == 0) return true;
            }
        }
        return false;
    }
};
