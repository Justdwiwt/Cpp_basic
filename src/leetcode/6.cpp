#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool down = false;
        for (auto c: s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) down = !down;
            curRow += down ? 1 : -1;
        }
        string ret;
        for (const auto &row: rows) ret += row;
        return ret;
    }
};
