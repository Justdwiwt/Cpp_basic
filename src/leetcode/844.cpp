#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return helper(S) == helper(T);
    }

    string helper(string str) {
        string res = "";
        for (char c : str) {
            if (c == '#') {
                if (!res.empty()) res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
