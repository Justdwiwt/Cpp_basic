#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> Q;
        TreeNode *p;
        Q.push(root);
        while (Q.empty() == 0) {
            vector<int> tmp;
            int width = Q.size();
            for (int i = 0; i < width; i++) {
                p = Q.front();
                tmp.push_back(p->val);
                Q.pop();
                if (p->left) Q.push(p->left);
                if (p->right) Q.push(p->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
