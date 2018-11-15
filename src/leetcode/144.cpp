#include <vector>
#include <stack>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
using namespace std;

//给定一个二叉树，返回它的 前序 遍历。
class Solution {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> node_stack;
        if (root != nullptr) node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode *tmpNode = node_stack.top();
            node_stack.pop();
            res.push_back(tmpNode->val);
            if (tmpNode->right) node_stack.push(tmpNode->right);
            if (tmpNode->left) node_stack.push(tmpNode->left);
        }
        return res;
    }
};

#pragma clang diagnostic pop