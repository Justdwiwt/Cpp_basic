#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int rows[9][10] = {{0}};
        int cols[9][10] = {{0}};
        int box[9][10] = {{0}};
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int C_cur = int(board[i][j] - '0');
                if (rows[i][C_cur]) return false;
                if (cols[j][C_cur]) return false;
                if (box[i / 3 * 3 + j / 3][C_cur]) return false;
                rows[i][C_cur] = 1;
                cols[j][C_cur] = 1;
                box[i / 3 * 3 + j / 3][C_cur] = 1;
            }
        return true;
    }
};
