#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(const string &word) {
        int cnt[26] = {}, key = 0, res = 0;
        for (char ch: word)
            ++cnt[ch - 'a'];
        sort(begin(cnt), end(cnt), greater<>());
        for (int c: cnt)
            res += (1 + key++ / 8) * c;
        return res;

    }
};
