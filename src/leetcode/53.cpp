#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN;
        int p = 0;
        for (int num:nums) {
            p = max(p + num, num);
            res = max(res, p);
        }
        return res;
    }
};
