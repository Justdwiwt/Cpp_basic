#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string> &A) {
        unordered_set<string> st;
        for (string word : A) {
            string even, odd;
            for (int i = 0; i < word.size(); ++i) {
                if (i % 2 == 0) even += word[i];
                else odd += word[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            st.insert(even + odd);
        }
        return st.size();
    }
};