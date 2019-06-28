#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> indexStk;
        for (int i = 0; i < n; i++) {
            while (!indexStk.empty() && T[i] > T[indexStk.top()]) {
                int top = indexStk.top();
                indexStk.pop();
                res[top] = i - top;
            }
            indexStk.push(i);
        }
        return res;
    }
};