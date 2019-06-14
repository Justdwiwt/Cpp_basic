#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> res;
        for (int i = 0; i < size; ++i) {
            int grayCode = i ^(i >> 1);
            res.push_back(grayCode);
        }
        return res;
    }
};
