#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string basicString = "$#";
        for (char i : s) {
            basicString += i;
            basicString += '#';
        }
        vector<int> rd(basicString.size(), 0);
        int pos = 0, mx = 0;
        int start = 0, maxLen = 0;
        for (int i = 1; i < basicString.size(); i++) {
            rd[i] = i < mx ? min(rd[2 * pos - i], mx - i) : 1;
            while (i + rd[i] < basicString.size() && i - rd[i] > 0 && basicString[i + rd[i]] == basicString[i - rd[i]])
                rd[i]++;
            if (i + rd[i] > mx) {
                pos = i;
                mx = i + rd[i];
            }
            if (rd[i] - 1 > maxLen) {
                start = (i - rd[i]) / 2;
                maxLen = rd[i] - 1;
            }
        }
        return s.substr(start, maxLen);
    }
};
