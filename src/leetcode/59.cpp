#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int >> generateMatrix(int n) {
        int k = 0;
        int count = 1;

        vector<vector<int>> res(n, vector<int>(n, 0));

        while (k <= (n - 1) / 2) {
            for (int i = k; i <= n - 1 - k; i++) {
                res[k][i] = count;
                count++;
            }
            for (int i = k + 1; i <= n - 1 - k; i++) {
                res[i][n - 1 - k] = count;
                count++;
            }
            for (int i = n - 2 - k; i >= k; i--) {
                res[n - 1 - k][i] = count;
                count++;
            }
            for (int i = n - 2 - k; i >= k + 1; i--) {
                res[i][k] = count;
                count++;
            }
            k++;
        }

        return res;
    }
};
