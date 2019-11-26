#include <vector>

using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) return 1.0;
        vector<double> sum(K + W);
        sum[0] = 1.0;
        for (int i = 1; i < K + W; ++i) {
            int t = min(i - 1, K - 1);
            if (i <= W) sum[i] = sum[i - 1] + sum[t] / W;
            else sum[i] = sum[i - 1] + (sum[t] - sum[i - W - 1]) / W;
        }
        return (sum[N] - sum[K - 1]) / (sum[K + W - 1] - sum[K - 1]);
    }
};
