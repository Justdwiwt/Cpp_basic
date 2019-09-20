#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &A) {
        int l = 0;
        int r = A.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[m] > A[m - 1] && A[m] > A[m + 1]) return m;
            else if (A[m] > A[m + 1]) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};
