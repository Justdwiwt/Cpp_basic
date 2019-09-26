#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        int l = 1;
        int r = 0;
        string res;
        for (auto i = 1; i < S.size(); ++i) {
            if (S[i] == '(') l++;
            else r++;
            if (r != l) res.push_back(S[i]);
            else {
                i++;
                l = 1;
                r = 0;
            }
        }
        return res;
    }
};
