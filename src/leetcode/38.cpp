#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        return func("1", 1, n);
    }

private:
    string func(string s, int depth, int n) {
        if (depth == n) return s;
        string res;
        int count = 1;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] == s[i + 1])
                count++;
            else {
                res += count + '0';
                res += s[i];
                count = 1;
            }
        return func(res, depth + 1, n);
    }
};
