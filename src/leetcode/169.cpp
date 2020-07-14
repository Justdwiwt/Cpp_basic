#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int res = 0;
        int cnt = 0;
        for (int num : nums)
            if (cnt == 0) {
                res = num;
                ++cnt;
            } else (num == res) ? ++cnt : --cnt;
        return res;
    }
};
