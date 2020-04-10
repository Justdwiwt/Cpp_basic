#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(num.begin(), num.end());
        helper(num, target, 0, out, res);
        return res;
    }

    void helper(vector<int> &num, int target, int start, vector<int> &out, vector<vector<int>> &res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(out);
            return;
        }
        for (int i = start; i < num.size(); ++i) {
            if (i > start && num[i] == num[i - 1]) continue;
            out.push_back(num[i]);
            helper(num, target - num[i], i + 1, out, res);
            out.pop_back();
        }
    }
};
