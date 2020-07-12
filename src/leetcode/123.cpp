#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n)return 0;
        int dp[n][2], min_p = prices[0];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            if (prices[i] <= min_p) {
                min_p = prices[i];
                continue;
            }
            for (int j = 0; j < i; j++)
                dp[i][0] = max(prices[i] - prices[j], dp[i][0]);
            for (int j = 0; j < i; j++)
                if (prices[i] > prices[j]) {
                    int mid = prices[i] - prices[j] + (j - 1 >= 0 ? dp[j - 1][0] : 0);
                    dp[i][1] = max(dp[i][1], mid);
                }
            min_p = min(min_p, prices[i]);
        }
        return dp[n - 1][1];
    }
};
