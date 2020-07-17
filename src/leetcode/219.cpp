#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int n = nums.size(), idx = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            auto iter = m.find(nums[i]);
            if (iter != m.end()) {
                if (i - iter->second <= k) return true;
                else iter->second = i;
            } else m[nums[i]] = i;
        }
        return false;
    }
};
