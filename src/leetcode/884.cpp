#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> res;
        unordered_map<string, int> wordCnt;
        istringstream iss(A + " " + B);
        while (iss >> A) ++wordCnt[A];
        for (const auto &a : wordCnt)
            if (a.second == 1) res.push_back(a.first);
        return res;
    }
};
