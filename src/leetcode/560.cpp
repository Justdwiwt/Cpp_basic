#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int p = 0;
        int res = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (int i:nums) {
            p += i;
            res += map.find(p - k) == map.end() ? 0 : map[p - k];
            ++map[p];
        }
        return res;
    }
};
