#include <string>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        string res;
        string str = "0123456789abcdef";
        int cnt = 0;
        while (num != 0 && cnt++ < 8) {
            res = str[(num & 0xf)] + res;
            num >>= 4;
        }
        return res.empty() ? "0" : res;
    }
};
