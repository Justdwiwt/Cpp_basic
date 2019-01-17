#include <vector>
#include <set>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        set<int> ans;

        for (auto i = 0; i < nums.size(); ++i)
            ans.insert(nums[i]);

        int min = 1;

        for (auto it = ans.begin(); it != ans.end(); ++it) {
            if (*it <= 0) continue;
            if (*it != min) return min;
            ++min;
        }

        return min;
    }
};


#pragma clang diagnostic pop