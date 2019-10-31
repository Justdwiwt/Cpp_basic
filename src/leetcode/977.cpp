#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {
        vector<int> res(A.size(), 0);
        int i = 0;
        int j = A.size() - 1;
        int k = A.size() - 1;
        while (i <= j)
            res[k--] = A[j] * A[j] > A[i] * A[i] ? A[j] * A[j--] : A[i] * A[i++];
        return res;
    }
};
