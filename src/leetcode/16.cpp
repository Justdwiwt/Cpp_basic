#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        long res = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int pStart = i + 1;
            int pEnd = nums.size() - 1;
            while (pStart < pEnd) {
                int sum = nums[i] + nums[pStart] + nums[pEnd];
                if (sum == target) {
                    pStart++;
                    pEnd--;
                } else sum > target ? (pEnd--) : (pStart++);
                if (abs(sum - target) < abs(res - target)) res = sum;
            }
        }
        return (int) res;
    }
};
