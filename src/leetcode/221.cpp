#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int height = matrix.size();
        if (height == 0)return 0;
        int width = matrix[0].size();
        if (width == 0)return 0;
        char max = '0';
        vector<vector<char>> dp(height + 1, vector<char>(width + 1, '0'));
        for (int i = 1; i <= height; i++)
            for (int j = 1; j <= width; j++)
                if (matrix[i - 1][j - 1] == '0')dp[i][j] = '0';
                else {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
                    max = max > dp[i][j] ? max : dp[i][j];
                }
        return (max - '0') * (max - '0');
    }
};
