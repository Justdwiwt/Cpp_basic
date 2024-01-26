#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        if (x > y) swap(x, y);
        vector<long long> A(n);
        for (int i = 1; i <= n; ++i) {
            A[0] += 2;
            A[min(i - 1, abs(i - y) + x)]--;
            A[min(n - i, abs(i - x) + 1 + n - y)]--;
            A[min(abs(i - x), abs(y - i) + 1)]++;
            A[min(abs(i - x) + 1, abs(y - i))]++;
            int r = max(x - i, 0) + max(i - y, 0);
            A[r + (y - x + 0) / 2]--;
            A[r + (y - x + 1) / 2]--;
        }
        for (int i = 1; i < n; ++i)
            A[i] += A[i - 1];
        return A;
    }
};
