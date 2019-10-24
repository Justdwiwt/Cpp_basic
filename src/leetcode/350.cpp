#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        for (auto i : nums1) ++map[i];
        for (auto i : nums2)
            if (map[i]-- > 0) res.push_back(i);
        return res;
    }
};
