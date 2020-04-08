#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void func(string sub, vector<string> &res, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(sub);
            return;
        }
        if (left > 0) func(sub + "(", res, left - 1, right);
        if (left < right) func(sub + ")", res, left, right - 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func("", res, n, n);
        return res;
    }
};
