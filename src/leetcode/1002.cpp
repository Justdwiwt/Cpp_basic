#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string> &A) {
        vector<string> ans;
        int count[26];
        for (int &i : count) {
            i = 101;
        }
        for (auto &i : A) {
            int word[26] = {0};
            for (char j : i)
                word[(int) j - 'a']++;
            for (auto k = 0; k < 26; k++)
                count[k] = min(count[k], word[k]);
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
