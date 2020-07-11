#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i) {
            res[i] = vector<int>(i + 1, 0);
            res[i][0] = 1;
            res[i][i] = 1;
        }
        if (numRows <= 2) return res;
        for (int i = 2; i < numRows; ++i)
            for (int j = 1; j < res[i].size() - 1; ++j)
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        return res;
    }
};
