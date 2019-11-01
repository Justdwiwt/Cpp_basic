#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> res(n, vector<int>(n, 0));
        return func(s, 0, n - 1, res);
    }

private:
    int func(string s, int i, int j, vector<vector<int>> &v) {
        if (i > j) return 0;
        if (v[i][j]) return v[i][j];
        v[i][j] = func(s, i + 1, j, v) + 1;
        for (auto k = i + 1; k <= j; ++k)
            if (s[k] == s[i])
                v[i][j] = min(v[i][j], func(s, i + 1, k - 1, v) + func(s, k, j, v));
        return v[i][j];
    }
};
