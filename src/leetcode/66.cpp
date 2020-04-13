#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        dfs(digits, len - 1);
        return digits;
    }

private:
    void dfs(vector<int> &digits, int deep) {
        if (digits[deep] == 9)
            if (deep == 0) {
                digits[deep] = 0;
                digits.insert(digits.begin(), 1);
            } else {
                digits[deep] = 0;
                dfs(digits, deep - 1);
            }
        else ++digits[deep];
    }
};
