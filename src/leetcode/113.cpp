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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> vec1;
        vector<int> vec2;
        solve(root, vec1, vec2, sum);
        return vec1;
    }

private:
    void solve(TreeNode *root, vector<vector<int>> &total, vector<int> thisTotal, int sum) {
        if (!root) return;
        sum -= root->val;
        thisTotal.push_back(root->val);
        if (!root->left && !root->right && sum == 0) total.push_back(thisTotal);
        solve(root->left, total, thisTotal, sum);
        solve(root->right, total, thisTotal, sum);
    }
};
