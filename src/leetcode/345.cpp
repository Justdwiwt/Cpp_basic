#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int pLeft = 0, pRight = s.size() - 1;
        while (pLeft < pRight) {
            if (isVowel(s[pLeft]) && isVowel(s[pRight]))
                swap(s[pLeft++], s[pRight--]);
            else if (isVowel(s[pLeft])) --pRight;
            else ++pLeft;
        }
        return s;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

// {a, e, i, o, u} upper and lower