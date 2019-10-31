#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    string tree2str(TreeNode *t) {
        if (!t) return "";
        string res = to_string(t->val);
        if (!t->left && !t->right) return res;
        res += "(" + tree2str(t->left) + ")";
        if (t->right) res += "(" + tree2str(t->right) + ")";
        return res;
    }
};
