#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int p = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            if (i > p) return false;
            p = max(p, i + nums[i]);
        }
        return true;
    }
};
