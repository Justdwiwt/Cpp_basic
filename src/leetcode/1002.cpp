#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string> &A) {
        vector<string> ans;
        int count[26];
        for (int i = 0; i < 26; ++i) {
            count[i] = 101;
        }
        for (int i = 0; i < A.size(); i++) {
            int word[26] = {0};
            for (int j = 0; j < A[i].size(); j++)
                word[(int) A[i][j] - 'a']++;
            for (int i = 0; i < 26; i++)
                count[i] = min(count[i], word[i]);
        }
        for (int i = 0; i < 26; i++)
            if (count[i])
                for (int j = 0; j < count[i]; j++) {
                    string str;
                    str.push_back((char) ('a' + i));
                    ans.push_back(str);
                }
        return ans;
    }
};
