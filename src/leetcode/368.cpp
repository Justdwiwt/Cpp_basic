#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        vector<pair<int, int>> dp(nums.size());
        int mx = 0;
        int mx_idx = 0;
        for (auto i = 0; i < nums.size(); ++i)
            for (auto j = i; j >= 0; --j)
                if (nums[i] % nums[j] == 0 && dp[i].first < dp[j].first + 1) {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = j;
                    if (mx < dp[i].first) {
                        mx = dp[i].first;
                        mx_idx = i;
                    }
                }
        for (auto i = 0; i < mx; ++i) {
            res.push_back(nums[mx_idx]);
            mx_idx = dp[mx_idx].second;
        }
        return res;
    }
};
