#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        for (auto i = 0; i < strs[0].length(); i++)
            for (auto j = 1; j < strs.size(); j++)
                if ((i >= strs[j].length()) || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
        return strs[0];
    }
};
