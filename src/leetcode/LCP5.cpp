#include <vector>
#include <cstring>

using namespace std;

struct Node {
    int leader;
    int sub;
    long add;
    long addC;
} node[50001];

class Solution {
public:
    int buildTree(int idx, vector<int> *child) {
        int sub = 1;
        for (auto next : child[idx]) {
            node[next].leader = idx;
            sub += buildTree(next, child);
        }
        return node[idx].sub = sub;
    }

    vector<int> bonus(int n, vector<vector<int>> &leadership, vector<vector<int>> &operations) {
        memset(node, 0, sizeof(node[0]) * (n + 1));
        vector<int> child[n + 1];
        for (auto &l: leadership) child[l[0]].push_back(l[1]);
        buildTree(1, child);
        int mod = 1e9 + 7;
        vector<int> ans;
        for (auto &op : operations) {
            int cr = op[1];
            if (op[0] == 1) {
                while (cr) {
                    node[cr].add += op[2];
                    cr = node[cr].leader;
                }
            } else if (op[0] == 2) {
                node[cr].addC += op[2];
                long added = node[cr].sub * op[2];
                while (cr = node[cr].leader)
                    node[cr].add += added;
            } else {
                int sub = node[cr].sub;
                long res = node[cr].addC * sub + node[cr].add;
                while (cr = node[cr].leader)
                    res += sub * node[cr].addC;
                ans.push_back(res % mod);
            }
        }
        return ans;
    }
};
