#include <vector>
#include <random>

using namespace std;

class Solution {
public:
    explicit Solution(vector<int> &nums) : v(nums) {}

    vector<int> reset() {
        return v;
    }

    vector<int> shuffle() {
        vector<int> res = v;
        for (auto i = 0; i < res.size(); ++i) {
            int t = i + random() % (res.size() - i);
            swap(res[i], res[t]);
        }
        return res;
    }

private:
    vector<int> v;
};
