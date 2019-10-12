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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return recFunc(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode *recFunc(vector<int> &preorder, vector<int> &inorder, int lPre, int rPre, int lMed, int rMed) {
        if (lPre > rPre) return nullptr;
        auto *root = new TreeNode(preorder[lPre]);
        for (int i = lMed; i <= rMed; ++i)
            if (preorder[lPre] == inorder[i]) {
                root->left = recFunc(preorder, inorder, lPre + 1, lPre + (i - lMed), lMed, i - 1);
                root->right = recFunc(preorder, inorder, lPre + (i - lMed) + 1, rPre, i + 1, rMed);
            }
        return root;
    }
};
