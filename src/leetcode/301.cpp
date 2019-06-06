#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        remove(move(s), {'(', ')'}, 0, 0, res);
        return res;
    }

    void remove(std::string s, const vector<char> &par, int m, int n, vector<string> &res) {
        int stack = 0, i = m;
        for (auto i = m; i < s.length(); ++i) {
            if (s[i] == par[0]) stack++;
            if (s[i] == par[1]) stack--;
            if (stack < 0) {
                // stack < 0 means "右"括号多出来了，删除右括号
                for (auto j = n; j <= i; ++j) {
                    if (s[j] == par[1] && (j == n || s[j - 1] != par[1])) {
                        auto ss = s.substr(0, j) + s.substr(j + 1);
                        remove(move(ss), par, i, j, res);
                    }
                }
                return;
            }
        }

        reverse(s.begin(), s.end());
        if (par[0] == '(') {
            remove(move(s), {par[1], par[0]}, 0, 0, res);
        } else {
            res.push_back(move(s));
        }
    }
};
