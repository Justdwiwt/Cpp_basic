#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool buddyStrings(const string &A, const string &B) {
        if (A.size() != B.size()) return false;
        if (A == B && unordered_set<char>(A.begin(), A.end()).size() < A.size()) return true;
        vector<int> diff;
        for (auto i = 0; i < A.size(); ++i)
            if (A[i] != B[i]) diff.push_back(i);
        return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
    }
};
