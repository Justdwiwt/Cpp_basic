#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        map<int, vector<string>> m;
        vector<char> chars;
        for (const auto &word : words)
            m[word.size()].push_back(word);
        for (auto c : licensePlate) {
            if (c >= 'a' && c <= 'z') chars.push_back(c);
            else if (c >= 'A' && c <= 'Z') chars.push_back(c + 32);
        }
        for (const auto &i : m) {
            if (i.first < chars.size()) continue;
            for (auto word : i.second) {
                bool flag = true;
                unordered_map<char, int> freq;
                for (auto c : word) ++freq[c];
                for (auto c : chars) {
                    if (--freq[c] < 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return word;
            }
        }
        return "";
    }
};
