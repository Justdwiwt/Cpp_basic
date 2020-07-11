#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> kRows(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            kRows[i] = 1;
            for (int j = i; j > 1; --j)
                kRows[j - 1] = kRows[j - 2] + kRows[j - 1];
        }
        return kRows;
    }
};
