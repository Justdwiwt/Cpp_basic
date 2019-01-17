#include <vector>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans;

        if (nums.empty()) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        int l = -1;
        int r = static_cast<int>(nums.size() - 1);
        int low = 0;
        int high = 0;

        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] < target) l = mid;
            else r = mid - 1;
        }

        low = l + 1;
        l = 0;
        r = static_cast<int>(nums.size());

        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > target) r = mid;
            else l = mid + 1;

        }

        high = r - 1;
        if (low > high) {
            ans.push_back(-1);
            ans.push_back(-1);
        } else {
            ans.push_back(low);
            ans.push_back(high);
        }

        return ans;

    }
};

#pragma clang diagnostic pop