#include <climits>
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
    int getMinimumDifference(TreeNode *root) {
        int res = INT_MAX;
        int pre = -1;
        inOrder(root, pre, res);
        return res;
    }

private:
    void inOrder(TreeNode *root, int &pre, int &res) {
        if (!root) return;
        inOrder(root->left, pre, res);
        if (pre != -1) res = min(res, root->val - pre);
        pre = root->val;
        inOrder(root->right, pre, res);
    }
};
