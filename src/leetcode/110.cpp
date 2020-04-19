#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) return true;
        bool flag = true;
        dfs(root, flag);
        return flag;
    }

private:
    int dfs(TreeNode *root, bool &flag) {
        if (flag == false) return -1;
        if (root == nullptr) return 0;
        int left = dfs(root->left, flag);
        int right = dfs(root->right, flag);
        if (abs(left - right) > 1) flag = false;
        return max(left, right) + 1;
    }
};
