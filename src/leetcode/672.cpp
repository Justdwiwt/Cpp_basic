#include <algorithm>

using namespace std;

class Solution {
public:
    int flipLights(int n, int m) {
        n = min(n, 3);
        return min(1 << n, 1 + m * n);
    }
};
