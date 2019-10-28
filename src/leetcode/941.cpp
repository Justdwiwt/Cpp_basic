#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int> &A) {
        if (A.empty()) return false;
        int index = 0;
        while (index < A.size() - 1)
            if (A[index] < A[index + 1]) index++;
            else break;
        if (index == 0 || index == A.size() - 1) return false;
        while (index < A.size() - 1) {
            if (A[index] <= A[index + 1]) return false;
            index++;
        }
        return true;
    }
};
