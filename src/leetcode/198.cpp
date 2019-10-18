#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int p1 = 0;
        int p2 = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                p2 += nums[i];
                p2 = max(p1, p2);
            } else {
                p1 += nums[i];
                p1 = max(p1, p2);
            }
        }
        return max(p1, p2);
    }
};
