#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        for (const auto &b: buildings) {
            h.emplace_back(b[0], -b[2]);
            h.emplace_back(b[1], b[2]);
        }
        sort(h.begin(), h.end());
        int pre = 0, cur;
        multiset<int> m;
        m.insert(0);
        for (const auto &e: h) {
            if (e.second < 0) m.insert(-e.second);
            else m.erase(m.find(e.second));
            cur = *m.rbegin();
            if (pre != cur) {
                res.push_back({e.first, cur});
                pre = cur;
            }
        }
        return res;
    }

private:
    vector<vector<int>> res;
    vector<pair<int, int>> h;
};
