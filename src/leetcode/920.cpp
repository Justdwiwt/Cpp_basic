#include <vector>

using namespace std;

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        long mod = 1000000007;
        vector<long> dp(N + 1, 0);
        dp[1] = N;
        for (int i = 2; i <= L; ++i)
            for (int j = min(i, N); j > 0; --j)
                dp[j] = (dp[j - 1] * (N - j + 1) + dp[j] * (j > K ? j - K : 0) + mod) % mod;
        return dp[N];
    }
};
