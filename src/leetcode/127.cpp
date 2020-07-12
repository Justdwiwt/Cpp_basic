#include <set>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> word_dic(wordList.begin(), wordList.end());
        unordered_set<string> begin_set = {std::move(beginWord)};
        unordered_set<string> end_set = {endWord};
        if (word_dic.count(endWord) == 0) return 0;
        int res = 1;
        for (; !begin_set.empty();) {
            res++;
            unordered_set<string> tmp_set;
            for (const auto &s:begin_set) word_dic.erase(s);
            for (const string &s:begin_set) {
                for (int i = s.size() - 1; i >= 0; i--) {
                    string str = s;
                    for (char c = 'a'; c <= 'z'; c++) {
                        str[i] = c;
                        if (word_dic.count(str) == 0) continue;
                        if (end_set.count(str) == 1) return res;
                        tmp_set.insert(str);
                    }
                }
            }
            if (tmp_set.size() < end_set.size()) begin_set = tmp_set;
            else {
                begin_set = end_set;
                end_set = tmp_set;
            }
        }
        return 0;
    }
};
