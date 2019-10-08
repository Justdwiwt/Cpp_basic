#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] > b[0]) return true;
            if (a[0] == b[0] && a[1] < b[1]) return true;
            return false;
        });

        vector<vector<int>> res;
        for (auto &e : people) {
            res.insert(res.begin() + e[1], e);
        }
        return res;
    }
};
