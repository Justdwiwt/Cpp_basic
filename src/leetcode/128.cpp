#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) return {};
        unordered_set<int> res;
        for (int num:nums) res.insert(num);
        int ans = -1;
        for (int num:nums) {
            if (res.find(num - 1) == res.end()) {
                int tmp = 1;
                while (res.find(num + tmp) != res.end()) tmp++;
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
