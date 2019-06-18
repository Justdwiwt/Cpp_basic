#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> path;
    vector<vector<string>> result;

    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return result;
    }

    bool isPalindrome(const string &s) {
        int begin = 0, end = s.length() - 1;
        while (begin < end) {
            if (s[begin] != s[end])
                return false;
            ++begin;
            --end;
        }
        return true;
    }

    void solve(const string &s, int pos) {
        if (pos == s.length()) {
            result.push_back(path);
            return;
        }
        for (auto i = pos; i < s.length(); ++i) {
            string prefix = s.substr(pos, i - pos + 1);
            if (!isPalindrome(prefix))
                continue;
            path.push_back(prefix);
            solve(s, i + 1);
            path.pop_back();
        }
    }
};
