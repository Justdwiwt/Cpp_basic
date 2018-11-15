#include <vector>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
using namespace std;

//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target
//写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        auto right = static_cast<int>(nums.size() - 1);
        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};

#pragma clang diagnostic pop