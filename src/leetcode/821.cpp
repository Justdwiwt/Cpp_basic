#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(const string &S, char C) {
        vector<int> res, idx;
        for (auto i = 0; i < S.size(); ++i)
            if (S[i] == C) idx.push_back(i);
        for (auto i = 0; i < S.size(); ++i) {
            auto it = lower_bound(idx.begin(), idx.end(), i);
            if (it == idx.end()) res.push_back(i - *(--it));
            else if (it == idx.begin()) res.push_back(*it - i);
            else {
                int d1 = *it - i, d2 = i - *(--it);
                res.push_back(min(d1, d2));
            }
        }
        return res;
    }
};
