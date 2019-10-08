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
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr)return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *current = q.front();
            TreeNode *tmp = nullptr;
            tmp = current->left;
            current->left = current->right;
            current->right = tmp;
            q.pop();
            if (current->left != nullptr)q.push(current->left);
            if (current->right != nullptr)q.push(current->right);
        }
        return root;
    }
};
