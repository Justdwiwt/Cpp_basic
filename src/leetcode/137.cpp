#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int sum = 0;
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            sum = 0;
            for (int n : nums) if ((n >> i) & 1) sum++;
            if (sum % 3) res |= 1 << i;
        }
        return res;
    }
};
