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
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) return 0;
        int aMax = root->val;
        maxPathHelper(root, aMax);
        return aMax;
    }

    int maxPathHelper(TreeNode *root, int &pMax) {
        if (root == nullptr) return 0;
        int aLeft = maxPathHelper(root->left, pMax);
        if (aLeft < 0) aLeft = 0;
        int aRight = maxPathHelper(root->right, pMax);
        if (aRight < 0) aRight = 0;
        int aNewMax = aLeft + aRight + root->val;
        if (aNewMax > pMax) pMax = aNewMax;
        return root->val + max(aLeft, aRight);
    }
};
