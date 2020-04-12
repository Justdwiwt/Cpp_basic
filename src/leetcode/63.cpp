#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> res(m, vector<long>(n));
        res[0][0] = !obstacleGrid[0][0];
        for (int i = 1; i < m; i++) res[i][0] = (obstacleGrid[i][0] || res[i - 1][0] == 0) ? 0 : 1;
        for (int i = 1; i < n; i++) res[0][i] = (obstacleGrid[0][i] || res[0][i - 1] == 0) ? 0 : 1;
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                res[i][j] = obstacleGrid[i][j] ? 0 : res[i - 1][j] + res[i][j - 1];
        return res[m - 1][n - 1];
    }
};
