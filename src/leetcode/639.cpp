#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(const string &s) {
        long e0 = 1;
        long e1 = 0;
        long e2 = 0;
        long f0 = 0;
        long M = 1e9 + 7;
        for (auto c : s) {
            if (c == '*') {
                f0 = 9 * e0 + 9 * e1 + 6 * e2;
                e1 = e0;
                e2 = e0;
            } else {
                f0 = (c > '0') * e0 + e1 + (c <= '6') * e2;
                e1 = (c == '1') * e0;
                e2 = (c == '2') * e0;
            }
            e0 = f0 % M;
        }
        return e0;
    }
};
