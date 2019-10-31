#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> res;
        string str;
        for (auto &i : s)
            if (i == ')') {
                while (res.top() != '(') {
                    str += res.top();
                    res.pop();
                }
                res.pop();

                for (auto &j:str) res.push(j);
                str = "";
            } else res.push(i);
        while (!res.empty()) {
            str += res.top();
            res.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
