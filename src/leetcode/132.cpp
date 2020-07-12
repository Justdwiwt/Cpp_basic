#include <set>
#include <vector>
#include <string>

using namespace std;

const int INF = 1e8;

class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        vector<vector<bool> > flags(N, vector<bool>(N, false));
        for (int i = 0; i < N; ++i) flags[i][i] = true;
        for (int len = 2; len <= N; ++len)
            for (int i = 0; i < N && i + len - 1 < N; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    flags[i][j] = (j - i > 1) ? flags[i + 1][j - 1] : true;
            }
        vector<int> dp(N, INF);
        dp[0] = 0;
        for (int i = 1; i < N; ++i) {
            if (flags[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 1; j <= i; ++j)
                if (flags[j][i]) dp[i] = min(dp[i], dp[j - 1] + 1);
        }
        return dp[N - 1];
    }
};
