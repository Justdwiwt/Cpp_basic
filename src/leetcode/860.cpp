#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        if (bills[0] != 5 || bills[1] == 20)
            return false;
        int n = 0;
        int m = 0;
        for (int bill : bills) {
            if (bill == 5) n++;
            else if (bill == 10) {
                if (n) {
                    n--;
                    m++;
                } else return false;
            } else {
                if (m) {
                    if (n) {
                        m--;
                        n--;
                        continue;
                    }
                }
                if (n >= 3) n -= 3;
                else return false;
            }
        }
        return true;
    }
};
