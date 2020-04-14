#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        int idx, v;
        while (l <= r) {
            idx = (l + r) / 2;
            v = matrix[idx / n][idx % n];
            if (target == v) return true;
            else {
                if (target < v) r = idx - 1;
                else l = idx + 1;
            }
        }
        return false;
    }
};
