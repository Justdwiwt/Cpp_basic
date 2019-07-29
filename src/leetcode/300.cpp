#include <vector>

using namespace std;

class Solution {
    int lengthOfLIS(vector<int> &nums) {
        vector<int> res;
        for (int num : nums) {
            auto key = lower_bound(res.begin(), res.end(), num);
            if (key == res.end()) {
                res.push_back(num);
            } else {
                *key = num;
            }
        }
        return res.size();
    }
};