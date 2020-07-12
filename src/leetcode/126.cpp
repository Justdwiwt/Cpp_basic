#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const int INF = 1 << 20;

class Solution {
public:
    vector<vector<string>> findLadders(const string &beginWord, const string &endWord, vector<string> &wordList) {
        int id = 0;
        for (const string &word : wordList)
            if (!wordId.count(word)) {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        if (!wordId.count(endWord)) return {};
        if (!wordId.count(beginWord)) {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        edges.resize(idWord.size());
        for (int i = 0; i < idWord.size(); i++)
            for (int j = i + 1; j < idWord.size(); j++)
                if (transformCheck(idWord[i], idWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
        const int dest = wordId[endWord];
        queue<vector<int>> q;
        vector<vector<string>> res;
        vector<int> cost(id, INF);
        q.push(vector<int>{wordId[beginWord]});
        cost[wordId[beginWord]] = 0;
        while (!q.empty()) {
            vector<int> now = q.front();
            q.pop();
            int last = now.back();
            if (last == dest) {
                vector<string> tmp;
                for (int index : now)
                    tmp.push_back(idWord[index]);
                res.push_back(tmp);
            } else {
                for (int i = 0; i < edges[last].size(); i++) {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }

    static bool transformCheck(const string &str1, const string &str2) {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++)
            if (str1[i] != str2[i]) ++differences;
        return differences == 1;
    }

private:
    vector<string> idWord;
    vector<vector<int>> edges;
    unordered_map<string, int> wordId;
};
