#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size();
        int iLen = nums.size();

        while (k > 0 && iLen > 1 && iLen != k) {
            for (int i = iLen - 1; i > k - 1; i--)
                swap(nums[i], nums[i - k]);
            int tmp = k;
            k = k - iLen % k;
            iLen = tmp;
        }
    }
};
