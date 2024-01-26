#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        return (n + max(0, n - 8) + max(0, n - 16) + max(0, n - 24) + max(0, n - 26));
    }
};
