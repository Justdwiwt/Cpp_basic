struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return !root ? true : recFunc(root->left, root->right);
    }

private:
    bool recFunc(TreeNode *left, TreeNode *right) {
        return !left && !right ?
               true : (left && !right) || (!left && right) || left->val != right->val ?
                      false : recFunc(left->left, right->right) && recFunc(left->right, right->left);
    }
};
