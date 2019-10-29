#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(const string &S) {
        int N = S.length();
        vector<int> P(N + 1);
        for (auto i = 0; i < N; ++i)
            P[i + 1] = P[i] + (S[i] == '1' ? 1 : 0);
        int res = INT_MAX;
        for (auto i = 0; i <= N; ++i)
            res = min(res, P[i] + N - i - (P[N] - P[i]));
        return res;
    }
};
