#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int mx = INT_MIN;
            for (auto i = 0; i < n; ++i) {
                TreeNode *t = q.front();
                q.pop();
                mx = max(mx, t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};
