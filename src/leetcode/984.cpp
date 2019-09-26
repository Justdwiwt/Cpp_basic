#include <string>

using namespace std;

class Solution {
public:
    string func(int A, int B, char a, char b) {
        if (A > B)
            return func(B, A, b, a);
        string res;
        int delta = A - (B + 1) / 2;
        while (A > 0 || B > 0) {
            if (B > 0) {
                res += string(min(2, B), b);
                B -= 2;
            }
            if (A > 0) {
                res += a;
                A -= 1;
            }
            if (delta > 0 && A > 0) {
                res += a;
                delta -= 1;
                A -= 1;
            }
        }
        return res;
    }

    string strWithout3a3b(int A, int B) {
        return func(A, B, 'a', 'b');
    }
};
