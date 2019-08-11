#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    struct Trie {
        int val;
        vector<Trie *> child;

        Trie() : child(vector<Trie *>(26, nullptr)), val(-1) {}
    };

    static void insert(string s, Trie *root) {
        for (int i = 0; i < s.size(); i++) {
            int num = s[i] - 'a';
            if (root->child[num] == nullptr) {
                root->child[num] = new Trie();
            }
            root = root->child[num];
            if (i != s.size() - 1 && root->val != 0)
                root->val = 1;
            else root->val = 0;
        }
    }

    static string search(string s, Trie *root) {
        string res;
        for (char i : s) {
            int num = i - 'a';
            if (root->child[num] == nullptr)
                break;
            root = root->child[num];
            res += i;
            if (root->val == 0)
                return res;
        }
        if (root->val == 0)
            return res;
        else return s;
    }

    string replaceWords(vector<string> &dict, const string &sentence) {
        Trie *root = new Trie();
        string res;
        for (const string &s:dict)
            insert(s, root);
        stringstream ss(sentence);
        string s;
        int sign = 1;
        while (ss >> s) {
            string temp = search(s, root);
            if (sign != 1)
                res += " ";
            if (temp.empty())
                res += s;
            else res += temp;
            sign++;
        }
        return res;
    }
};
