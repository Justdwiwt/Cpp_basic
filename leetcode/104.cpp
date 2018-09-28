#include <w32api/ntdef.h>
#include "Lbd.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#pragma ide diagnostic ignored "hicpp-explicit-conversions"

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // NOLINT(google-explicit-constructor)

#pragma clang diagnostic pop
};

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

#pragma clang diagnostic pop