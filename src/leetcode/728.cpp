#include <vector>
#include <string>
#include <sstream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
using namespace std;

//自除数 是指可以被它包含的每一位数除尽的数。
//
//例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
//
//还有，自除数不允许包含 0 。
//
//给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for (int i = left; i <= right; ++i) {
            stringstream ss;
            ss << i;
            string s = ss.str();
            int l = static_cast<int>(s.length()), t = 0;
            for (int j = 0; j < l; ++j) {
                if (s[j] == '0')
                    break;
                if (i % (s[j] - '0') == 0)
                    t++;
            }
            if (l == t)
                v.push_back(i);
        }
        return v;
    }
};

#pragma clang diagnostic pop