#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size(), sum = 0, id = 0, min_sum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < min_sum) {
                id = i;
                min_sum = sum;
            }
        }
        return sum >= 0 ? (id + 1) % n : -1;
    }
};
