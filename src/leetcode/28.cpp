#include <string>
#include <vector>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = -1;
        int len1 = static_cast<int>(haystack.size());
        int len2 = static_cast<int>(needle.size());

        while (++i <= len1 - len2) {
            string tem = haystack.substr(static_cast<unsigned long>(i), static_cast<unsigned long>(len2));
            if (tem == needle) return i;
        }

        return -1;
    }

private:
    int strStrKMP(string haystack, string needle) {
        int i = 0;
        int k = 0;
        int len1 = static_cast<int>(haystack.size());
        int len2 = static_cast<int>(needle.size());
        if (len2 == 0 || haystack == needle) return 0;

        vector<int> index(len2, 0);

        for (i = 1; i < len2; ++i) {
            while (k > 0 && needle[i] != needle[k]) k = index[k - 1];
            index[i] = (k += needle[i] == needle[k]);
        }
        for (i = 0, k = 0; i < len1; ++i) {
            while (k > 0 && haystack[i] != needle[k]) k = index[k - 1];
            k += needle[k] == haystack[i];
            if (k == len2) return i - len2 + 1;
        }

        return -1;
    }
};

#pragma clang diagnostic pop