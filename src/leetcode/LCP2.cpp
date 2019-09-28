#include <vector>

using namespace std;

class Solution {
public:
    vector<int> count(vector<int> &cont) {
        int index = cont.size() - 1;
        int a = 1;
        int b = cont[index];
        for (int i = index - 1; i >= 1; --i) {
            int tmp = a;
            a = b;
            b = b * cont[i] + tmp;
        }
        return {a, b};
    }

    vector<int> fraction(vector<int> &cont) {
        if (cont.size() == 1) return {cont[0], 1};
        else {
            vector<int> right = count(cont);
            return {cont[0] * right[1] + right[0], right[1]};
        }
    }
};
