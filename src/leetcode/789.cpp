#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        int dist = abs(target[0]) + abs(target[1]);
        for (auto ghost : ghosts) {
            int t = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            if (t <= dist) return false;
        }
        return true;
    }
};
