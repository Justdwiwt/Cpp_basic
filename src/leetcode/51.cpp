#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<bool> Line(n, false);
        vector<bool> Incline1(2 * n - 1, false);
        vector<bool> Incline2(2 * n - 1, false);
        vector<vector<bool>> Q(N, Line);
        nQueen(0, Q, Line, Incline1, Incline2);
        return res;
    }

    void nQueen(int n, vector<vector<bool>> &Q, vector<bool> &line, vector<bool> &incline1, vector<bool> &incline2) {
        if (n == N) {
            string a;
            vector<string> b;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (Q[i][j]) a.push_back('Q');
                    else a.push_back('.');
                }
                b.push_back(a);
                a.clear();
            }
            res.push_back(b);
            return;
        }
        for (int i = 0; i < N; i++)
            if (!line[i] && !incline1[n - i + N - 1] && !incline2[n + i]) {
                incline1[n - i + N - 1] = true;
                incline2[n + i] = true;
                Q[n][i] = true;
                line[i] = true;
                nQueen(n + 1, Q, line, incline1, incline2);
                incline1[n - i + N - 1] = false;
                incline2[n + i] = false;
                Q[n][i] = false;
                line[i] = false;
            }
    }

private:
    int N;
    vector<vector<string>> res;
};
