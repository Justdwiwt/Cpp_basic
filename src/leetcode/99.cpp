struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *pre = nullptr;
        TreeNode *curr = root;
        TreeNode *tmp = nullptr;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                if ((pre != nullptr) && (pre->val > curr->val)) {
                    if (first == nullptr) {
                        first = pre;
                        second = curr;
                    } else second = curr;
                }
                pre = curr;
                curr = curr->right;
            } else {
                tmp = curr->left;
                while ((tmp->right != nullptr) && (tmp->right != curr)) tmp = tmp->right;
                if (tmp->right == nullptr) {
                    tmp->right = curr;
                    curr = curr->left;
                } else {
                    tmp->right = nullptr;
                    if ((pre != nullptr) && (pre->val > curr->val)) {
                        if (first == nullptr) {
                            first = pre;
                            second = curr;
                        } else second = curr;
                    }
                    pre = curr;
                    curr = curr->right;
                }
            }
        }
        int v = first->val;
        first->val = second->val;
        second->val = v;
    }
};
