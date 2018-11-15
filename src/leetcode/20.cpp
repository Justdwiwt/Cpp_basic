#include <string>
#include <stack>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
using namespace std;

/**
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 */
class Solution {
public:
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"

    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        st.push('#');
        while (i < s.size()) {
            if ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') ||
                (s[i] == '}' && st.top() == '{')) {
                i++;
                st.pop();
            } else {
                st.push(s[i]);
                i++;
            }
        }
        if (st.top() == '#')
            return true;
        return false;
    }

#pragma clang diagnostic pop
};

#pragma clang diagnostic pop