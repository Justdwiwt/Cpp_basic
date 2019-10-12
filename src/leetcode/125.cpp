#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int pLeft = 0;
        int pRight = s.size() - 1;
        while (pLeft <= pRight) {
            while (!isalnum(s[pLeft]) && pLeft < pRight) pLeft++;
            while (!isalnum(s[pRight]) && pLeft < pRight) pRight--;
            if (toupper(s[pLeft]) != toupper(s[pRight])) return false;
            pLeft++;
            pRight--;
        }
        return true;
    }
};
