#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> numStr;
        for (auto num : nums)
            numStr.push_back(to_string(num));
        sort(numStr.begin(), numStr.end(), cmp);
        if (!numStr.empty() && numStr[0] == "0")
            return "0";
        string s;
        for (const string &num:numStr)
            s += num;
        return s;
    }

    static bool cmp(const string &i, const string &j) {
        return i + j > j + i;
    }
};
