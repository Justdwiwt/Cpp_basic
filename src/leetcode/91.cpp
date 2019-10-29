#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int a = 1;
        int b = 1;
        int n = s.size();
        for (auto i = 1; i < n; ++i) {
            if (s[i] == '0') a = 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                a = a + b;
                b = a - b;
            } else b = a;
        }
        return a;
    }
};
