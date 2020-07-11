#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int max = 0;
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            sum = std::max(0, sum + prices[i] - prices[i - 1]);
            max = std::max(max, sum);
        }
        return max;
    }
};
