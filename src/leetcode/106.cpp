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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(rbegin(inorder), rend(inorder),
                         rbegin(postorder), rend(postorder));
    }

    template<typename RandomIt>
    TreeNode *buildTree(RandomIt in_rfirst, RandomIt in_rlast,
                        RandomIt post_rfirst, RandomIt post_rlast) {
        if (in_rfirst == in_rlast) return nullptr;
        if (post_rfirst == post_rlast) return nullptr;

        auto root = new TreeNode(*post_rfirst);

        auto inRootRPos = find(in_rfirst, in_rlast, *post_rfirst);
        auto RightSize = distance(in_rfirst, inRootRPos);

        root->right = buildTree(in_rfirst,
                                next(in_rfirst, RightSize),
                                next(post_rfirst),
                                next(post_rfirst, RightSize + 1));
        root->left = buildTree(next(inRootRPos),
                               in_rlast,
                               next(post_rfirst, RightSize + 1),
                               post_rlast);
        return root;
    }
};
