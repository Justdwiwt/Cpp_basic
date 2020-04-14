#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        string dir;
        for (auto c : path)
            if (c == '/') {
                if (dir == ".." && !st.empty()) st.pop();
                else if (dir != ".." && dir != "." && !dir.empty()) st.push(dir);
                dir.clear();
            } else dir += c;
        string res;
        while (!st.empty()) {
            string s = st.top();
            st.pop();
            res = "/" + s + res;
        }
        if (res.empty()) res = "/";
        return res;
    }
};
