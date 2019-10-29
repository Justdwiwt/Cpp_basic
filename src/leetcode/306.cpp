#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(const string &num) {
        for (auto i = 1; i < num.size(); ++i) {
            string s1 = num.substr(0, i);
            if (s1.size() > 1 && s1[0] == 0) break;
            for (auto j = i + 1; j < num.size(); ++j) {
                string s2 = num.substr(i, j - i);
                if (s2.size() > 1 && s2[0] == 0) break;
                if (helper(num.substr(j), s1, s2)) return true;
            }
        }
        return false;
    }

private:
    bool helper(const string &num, string num1, string num2) {
        if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) return false;
        string sumStr = add(num1, num2);
        if (sumStr == num) return true;
        if (sumStr.size() >= num.size() || num.substr(0, sumStr.size()) != sumStr) return false;
        return helper(num.substr(sumStr.size()), num2, sumStr);
    }

    string add(string num1, string num2) {
        string res;
        int i = (int) num1.size() - 1;
        int j = (int) num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int val1 = (i >= 0) ? (num1[i--] - '0') : 0;
            int val2 = (j >= 0) ? (num2[j--] - '0') : 0;
            int sum = val1 + val2 + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
