#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            string str = to_string(nums[i]);
            int pos = i;
            while (i < nums.size() - 1 && nums[i] + 1 == nums[i + 1]) i++;
            if (pos != i)
                str += "->" + to_string(nums[i]);
            res.push_back(str);
        }
        return res;
    }
};
