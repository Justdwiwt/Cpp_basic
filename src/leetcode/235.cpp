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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *pp = root;
        TreeNode *qq = root;
        while (pp != nullptr) {
            left.push_back(pp);
            if (p->val < pp->val) pp = pp->left;
            else if (p->val > pp->val) pp = pp->right;
            else break;
        }
        while (qq != nullptr) {
            right.push_back(qq);
            if (q->val < qq->val) qq = qq->left;
            else if (q->val > qq->val) qq = qq->right;
            else break;
        }
        int i = 0;
        int j = 0;
        TreeNode *temp;
        while (i < left.size() && j < right.size()) {
            if (left[i] == right[j]) temp = left[i];
            i++;
            j++;
        }
        return temp;
    }

private:
    vector<TreeNode *> left;
    vector<TreeNode *> right;
};
