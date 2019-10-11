#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        istringstream is(str);
        is >> ans;
        return ans;
    }
};
