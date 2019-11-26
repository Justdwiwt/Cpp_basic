#include <vector>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
        int res = 0;
        vector<vector<int>> mat(N, vector<int>(N, 1));
        for (auto mine : mines) mat[mine[0]][mine[1]] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int k = 0;
                while (canExpand(mat, N, i, j, k)) ++k;
                res = max(res, k);
            }
        }
        return res;
    }

    bool canExpand(vector<vector<int>> &mat, int N, int x, int y, int k) {
        if (x - k < 0 || y - k < 0 || x + k >= N || y + k >= N) return false;
        return mat[x - k][y] && mat[x][y + k] && mat[x + k][y] && mat[x][y - k];
    }
};