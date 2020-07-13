#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int op = (int) tokens.size() - 1;
        return helper(tokens, op);
    }

private:
    int helper(vector<string> &tokens, int &op) {
        string str = tokens[op];
        if (str != "+" && str != "-" && str != "*" && str != "/") return stoi(str);
        int num1 = helper(tokens, --op);
        int num2 = helper(tokens, --op);
        if (str == "+") return num2 + num1;
        if (str == "-") return num2 - num1;
        if (str == "*") return num2 * num1;
        return num2 / num1;
    }
};
