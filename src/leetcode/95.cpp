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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};
        return helper(1, n);
    }

private:
    vector<TreeNode *> helper(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode *> res;
        for (int i = start; i <= end; i++) {
            auto left = helper(start, i - 1), right = helper(i + 1, end);
            for (auto a:left)
                for (auto b:right) {
                    auto *node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
        }
        return res;
    }
};
