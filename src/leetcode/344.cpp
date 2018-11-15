#include <string>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"

using namespace std;

class Solution {
public:
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

    string reverseString(string s) { // NOLINT(performance-unnecessary-value-param)
        string ret;
        if (s.empty()) return ret;
        string::const_iterator tail = s.cend();
        do {
            tail--;
            ret.push_back(*tail);
        } while (tail != s.cbegin());
        return ret;
    }

#pragma clang diagnostic pop
};

#pragma clang diagnostic pop