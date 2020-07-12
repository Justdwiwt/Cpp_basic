#include <vector>
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
    TreeNode *buildTree(vector<int> &in_order, vector<int> &post_order) {
        return buildTree(rbegin(in_order), rend(in_order),
                         rbegin(post_order), rend(post_order));
    }

    template<typename RandomIt>
    TreeNode *buildTree(RandomIt in_rFirst, RandomIt in_rLast,
                        RandomIt post_rFirst, RandomIt post_rLast) {
        if (in_rFirst == in_rLast) return nullptr;
        if (post_rFirst == post_rLast) return nullptr;

        auto root = new TreeNode(*post_rFirst);

        auto inRootRPos = find(in_rFirst, in_rLast, *post_rFirst);
        auto RightSize = distance(in_rFirst, inRootRPos);

        root->right = buildTree(in_rFirst,
                                next(in_rFirst, RightSize),
                                next(post_rFirst),
                                next(post_rFirst, RightSize + 1));
        root->left = buildTree(next(inRootRPos),
                               in_rLast,
                               next(post_rFirst, RightSize + 1),
                               post_rLast);
        return root;
    }
};
