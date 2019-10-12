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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return recFunc(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *recFunc(vector<int> &nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        auto *root = new TreeNode(nums[mid]);
        root->left = recFunc(nums, left, mid - 1);
        root->right = recFunc(nums, mid + 1, right);
        return root;
    }
};
