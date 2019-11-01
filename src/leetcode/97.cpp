#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        unordered_set<int> s;
        return dfs(s1, 0, s2, 0, s3, 0, s);
    }

private:
    bool dfs(string &s1, int i, string &s2, int j, string &s3, int k, unordered_set<int> &s) {
        int key = i * s3.size() + j;
        if (s.count(key)) return false;
        if (i == s1.size()) return s2.substr(j) == s3.substr(k);
        if (j == s2.size()) return s1.substr(i) == s3.substr(k);
        if ((s1[i] == s3[k] && dfs(s1, i + 1, s2, j, s3, k + 1, s)) ||
            (s2[j] == s3[k] && dfs(s1, i, s2, j + 1, s3, k + 1, s)))
            return true;
        s.insert(key);
        return false;
    }
};