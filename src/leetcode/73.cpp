#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.size() == 0) return;
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool firstRow = false;
        bool firstCol = false;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                const int item = matrix[i][j];
                if (item == 0) {
                    if (i == 0) firstRow = true;
                    if (j == 0) firstCol = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
        if (firstRow) for (int i = 0; i < n; i++) matrix[0][i] = 0;
        if (firstCol) for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};
