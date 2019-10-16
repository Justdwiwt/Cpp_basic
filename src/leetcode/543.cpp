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
    int diameterOfBinaryTree(TreeNode *root) {
        int distance = 0;
        dfs(root, distance);
        return distance;
    }

private:
    int dfs(TreeNode *root, int &distance) {
        if (root == nullptr) return 0;
        int left = dfs(root->left, distance);
        int right = dfs(root->right, distance);
        distance = max(left + right, distance);
        return max(left, right) + 1;
    }
};
