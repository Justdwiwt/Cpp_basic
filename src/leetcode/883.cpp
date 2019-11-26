#include <vector>

using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int n = grid[0].size(), res = 0;
        for (int i = 0; i < n; ++i) {
            int row = 0, col = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) ++res;
                row = max(row, grid[i][j]);
                col = max(col, grid[j][i]);
            }
            res += row + col;
        }
        return res;
    }
};
