#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int n = str.size();
        int j = n;
        for (auto i = n - 1; i > 0; --i) {
            if (str[i] >= str[i - 1]) continue;
            --str[i - 1];
            j = i;
        }
        for (auto i = j; i < n; ++i) str[i] = '9';
        return stoi(str);
    }
};
