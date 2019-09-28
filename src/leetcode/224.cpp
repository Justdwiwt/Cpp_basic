#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
private:
    stack<int> num;
    stack<char> op;

    int symbol(char a) {
        switch (a) {
            case '+':
                return 1;
            case '-':
                return 1;
            case '*':
                return 2;
            case '/':
                return 2;
            case '(':
                return 3;
            default:
                return -1;
        }
    }

    void cal() {
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        switch (op.top()) {
            case '+':
                num.push(a + b);
                break;
            case '-':
                num.push(a - b);
                break;
            case '*':
                num.push(a * b);
                break;
            case '/':
                num.push(a / b);
                break;
        }
        op.pop();
    }

public:
    int calculate(const string &s) {
        string str;
        for (char i : s) {
            if (isdigit(i))
                str += i;
            else if (i == ' ') continue;
            else {
                if (!str.empty()) {
                    num.push(stoi(str));
                    str.clear();
                }
                if (op.empty() || i == '(' || symbol(op.top()) < symbol(i))
                    op.push(i);
                else if (i == ')') {
                    while (op.top() != '(') cal();
                    op.pop();
                } else {
                    while (!op.empty() && symbol(op.top()) <= symbol(i)) cal();
                    op.push(i);
                }
            }
        }
        if (!str.empty()) num.push(stoi(str));
        while (!op.empty()) cal();
        return num.top();
    }
};
