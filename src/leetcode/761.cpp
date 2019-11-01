#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string S) {
        int cnt = 0, i = 0;
        vector<string> v;
        string res;
        for (int j = 0; j < S.size(); ++j) {
            cnt += (S[j] == '1') ? 1 : -1;
            if (cnt == 0) {
                v.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(v.begin(), v.end(), greater<>());
        for (const auto &s : v) res += s;
        return res;
    }
};
