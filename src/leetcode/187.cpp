#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res, st;
        for (int i = 0; i + 9 < s.size(); ++i) {
            string t = s.substr(i, 10);
            if (st.count(t)) res.insert(t);
            else st.insert(t);
        }
        return vector<string>{res.begin(), res.end()};
    }
};
