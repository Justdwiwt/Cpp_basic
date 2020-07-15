#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
    int index = 0;

    void getVec(TreeNode *root) {
        if (root == nullptr) return;
        getVec(root->left);
        diff.push_back(root->val);
        getVec(root->right);
    }

    BSTIterator(TreeNode *root) {
        getVec(root);
    }

    /** @return the next smallest number */
    int next() {
        return diff[index++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (index < diff.size()) return true;
        return false;
    }

private:
    vector<int> diff;
};
