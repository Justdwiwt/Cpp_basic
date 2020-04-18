#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void helper(TreeNode *root, int l) {
        if (!root) return;
        m[l].emplace_back(root->val);
        helper(root->left, l + 1);
        helper(root->right, l + 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        helper(root, 0);
        vector<vector<int>> res;
        for (int i = m.size() - 1; i >= 0; i--) res.push_back(m[i]);
        return res;
    }

private:
    unordered_map<int, vector<int>> m;
};
