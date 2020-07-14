#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            if (n == 0) break;
            if (n % 26 == 0) {
                res = 'Z' + res;
                n /= 26;
                n--;
            } else {
                res = (char) ('A' + n % 26 - 1) + res;
                n /= 26;
            }
        }
        return res;
    }
};
