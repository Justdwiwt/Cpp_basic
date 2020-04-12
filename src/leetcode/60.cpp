#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = string("123456789").substr(0, n);
        for (int j = 1; j < k; ++j) next_permutation(s.begin(), s.end());
        return s;
    }
};
