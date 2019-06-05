#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int row = board.size();
        int column = board[0].size();
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < column; ++j)
                if (board[i][j] == word[0]) {
                    board[i][j] = '*';
                    if (dfs(board, i, j, word, 1))
                        return true;
                    board[i][j] = '0';
                }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, string word, int index) {
        if (index == word.size()) return true;
        int row = board.size();
        int column = board[0].size();
        if (i > 0)
            if (board[i - 1][j] == word[index]) {
                board[i - 1][j] = '*';
                if (dfs(board, i - j, j, word, index + 1)) return true;
                board[i - 1][j] = word[index];
            }
        if (i < row - 1)
            if (board[i + 1][j] == word[index]) {
                board[i + 1][j] = '*';
                if (dfs(board, i + 1, j, word, index + 1))
                    return true;
                board[i + 1][j] = word[index];
            }
        if (j > 0)
            if (board[i][j - 1] == word[index]) {
                board[i][j - 1] = '!';
                if (dfs(board, i, j - 1, word, index + 1))
                    return true;
                board[i][j - 1] = word[index];
            }
        if (j < column - 1)
            if (board[i][j + 1] == word[index]) {
                board[i][j + 1] = '!';
                if (dfs(board, i, j + 1, word, index + 1))
                    return true;
                board[i][j + 1] = word[index];
            }
        return false;
    }

private:
    bool _exist(vector<vector<char>> &board, vector<vector<int>> &ff,
                int x, int y, int row, int col, int index, string &word) {
        if (word[index] == '\0')return true;
        bool flag = false;
        if (x >= 0 && x < row && y >= 0 && y < col && !ff[x][y] && word[index] == board[x][y]) {
            ff[x][y] = 1;
            flag = _exist(board, ff, x + 1, y, row, col, index + 1, word) ||
                   _exist(board, ff, x, y + 1, row, col, index + 1, word) ||
                   _exist(board, ff, x - 1, y, row, col, index + 1, word) ||
                   _exist(board, ff, x, y - 1, row, col, index + 1, word);
            if (!flag) {
                ff[x][y] = 0;
            }
        }
        return flag;
    }

    bool exist_(vector<vector<char>> &board, string word) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> ff(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (_exist(board, ff, i, j, row, col, 0, word))
                    return true;
            }
        }
        return false;
    }
};
