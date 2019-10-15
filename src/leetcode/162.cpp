#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int pLeft = 0;
        int pRight = nums.size() - 1;
        while (pLeft < pRight) {
            int mid = pLeft + (pRight - pLeft >> 1);
            mid == nums.size() - 1 || nums[mid] > nums[mid + 1] ? (pRight = mid) : (pLeft = mid + 1);
        }
        return pLeft;
    }
};
