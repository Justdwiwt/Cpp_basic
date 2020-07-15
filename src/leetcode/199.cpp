#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *root, int depth) {
        if (root == NULL) return;
        if (res.size() == depth) res.push_back(root->val);
        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }

private:
    vector<int> res;
};
