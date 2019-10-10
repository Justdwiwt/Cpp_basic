#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        map<char, string> m = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };
        string head;
        queue<string> q;
        for (char i : m[digits[0]]) {
            string str;
            str.push_back(i);
            q.push(str);
        }
        for (int j = 1; j < digits.size(); ++j) {
            int qSize = q.size();
            while (qSize--) {
                for (char i : m[digits[j]]) {
                    head = q.front();
                    head = head + i;
                    q.push(head);
                }
                q.pop();
            }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
