#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty()) return 0;
        else if (nums.size() == 1) return nums[0];
        int p = nums[0];
        int max_P = nums[0];
        int min_P = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int t = max_P;
            max_P = max(max(max_P * nums[i], nums[i]), min_P * nums[i]);
            min_P = min(min(t * nums[i], nums[i]), min_P * nums[i]);
            p = max(max_P, p);
        }
        return p;
    }
};
