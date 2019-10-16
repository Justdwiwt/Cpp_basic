struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *convertBST(TreeNode *root) {
        int pre = 0;
        func(root, pre);
        return root;
    }

private:
    void func(TreeNode *node, int &pre) {
        if (node) {
            func(node->right, pre);
            node->val += pre;
            pre = node->val;
            func(node->left, pre);
        }
    }
};
