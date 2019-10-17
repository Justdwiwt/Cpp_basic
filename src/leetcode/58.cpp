#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        istringstream ss(s);
        string res;
        while (ss >> res) return res.size();
        return 0;
    }
};
