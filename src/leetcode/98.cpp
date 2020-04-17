struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return helper(root, nullptr, nullptr);
    }

    bool helper(TreeNode *root, int *low, int *high) {
        if (root == nullptr) return true;
        int *val;
        val = &root->val;
        if (low != nullptr && *val <= *low) return false;
        if (high != nullptr && *val >= *high) return false;
        if (!helper(root->right, val, high)) return false;
        if (!helper(root->left, low, val)) return false;
        return true;
    }
};
