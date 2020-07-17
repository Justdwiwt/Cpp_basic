#include <string>

using namespace std;

class Solution {
public:
    int calculate(const string &s) {
        int pre = 0, cur = 0, next = 0;
        char sign = '+';
        for (char ch : s) {
            if (ch == ' ') continue;
            if (ch >= '0' && ch <= '9') {
                next = 10 * next + (ch - '0');
            } else {
                process(pre, cur, next, sign);
                sign = ch;
            }
        }
        process(pre, cur, next, sign);
        return pre + cur;
    }

private:
    static void process(int &pre, int &cur, int &next, char sign) {
        if (sign == '+') {
            pre += cur;
            cur = next;
        } else if (sign == '-') {
            pre += cur;
            cur = -next;
        } else if (sign == '*') cur *= next;
        else cur /= next;
        next = 0;
    }
};
