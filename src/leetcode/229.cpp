#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> res;
        int a = 0;
        int b = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();
        for (auto num:nums) {
            if (num == a)++cnt1;
            else if (num == b)++cnt2;
            else if (cnt1 == 0) {
                a = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                b = num;
                cnt2 = 1;
            } else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = cnt2 = 0;
        for (auto num:nums) {
            if (num == a)++cnt1;
            else if (num == b)++cnt2;
        }
        if (cnt1 > n / 3)res.push_back(a);
        if (cnt2 > n / 3)res.push_back(b);
        return res;
    }
};
