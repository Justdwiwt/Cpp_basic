#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int> &rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int rod : rods) {
            auto cur = dp;
            for (const auto &kv : cur) {
                const int k = kv.first;
                dp[k + rod] = max(dp[k + rod], cur[k]);
                dp[abs(k - rod)] = max(dp[abs(k - rod)], cur[k] + min(rod, k));
            }
        }
        return dp[0];
    }
};
