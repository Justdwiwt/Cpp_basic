#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        int val = 0;
        int curr = 0;
        inOrder(root, curr, k, val);
        return val;
    }

    void inOrder(TreeNode *root, int &curr, int k, int &val) {
        if (!root) return;
        inOrder(root->left, curr, k, val);
        curr++;
        if (curr == k) {
            val = root->val;
            return;
        }
        inOrder(root->right, curr, k, val);
    }
};
