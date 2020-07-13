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
    vector<int> postorderTraversal(TreeNode *root) {
        if (root) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            res.push_back(root->val);
        }
        return res;
    }

private:
    vector<int> res;
};
