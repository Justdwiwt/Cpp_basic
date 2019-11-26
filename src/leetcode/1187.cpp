#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int dp[2001][2001] = {};

    int dfs(vector<int> &a1, vector<int> &a2, int i1, int i2, int prev) {
        if (i1 >= a1.size()) return 0;
        i2 = upper_bound(begin(a2) + i2, end(a2), prev) - begin(a2);
        if (dp[i1][i2]) return dp[i1][i2];
        auto r1 = 3000, r2 = 3000;
        if (i2 < a2.size())
            r2 = 1 + dfs(a1, a2, i1 + 1, i2 + 1, a2[i2]); // replace with smallest      
        if (prev < a1[i1])
            r1 = dfs(a1, a2, i1 + 1, i2, a1[i1]); // keep
        return dp[i1][i2] = min(r1, r2);
    }

    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        sort(begin(arr2), end(arr2));
        auto res = dfs(arr1, arr2, 0, 0, INT_MIN);
        return res == 3000 ? -1 : res;
    }
};
