#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int result = 0;
        if (matrix.empty()) return result;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<vector<int >>> dp(m, vector<vector<int >>(n, {0, 0, 0}));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == '1') {
                    if (i == 0 && j == 0) dp[i][j] = {1, 1, 1};
                    else if (i == 0) dp[i][j] = {dp[i][j - 1][0] + 1, 1, dp[i][j - 1][2] + 1};
                    else if (j == 0) dp[i][j] = {1, dp[i - 1][j][1] + 1, dp[i - 1][j][2] + 1};
                    else {
                        dp[i][j][0] = dp[i][j - 1][0] + 1;
                        dp[i][j][1] = dp[i - 1][j][1] + 1;
                        int col_min = dp[i][j][0];
                        int row = dp[i][j][1];
                        for (int k = 0; k < row; k++) {
                            col_min = min(col_min, dp[i - k][j][0]);
                            dp[i][j][2] = max(dp[i][j][2], col_min * (k + 1));
                        }
                    }
                    result = max(result, dp[i][j][2]);
                }
        return result;
    }
};
