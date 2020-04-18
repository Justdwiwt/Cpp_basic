#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        vector<int> sub_res;
        bool level = false;

        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty()) {
            while (q.front() != nullptr) {
                TreeNode *tmp = q.front();
                q.pop();

                sub_res.push_back(tmp->val);

                if (tmp->left != nullptr)
                    q.push(tmp->left);
                if (tmp->right != nullptr)
                    q.push(tmp->right);
            }

            q.pop();

            if (!sub_res.empty()) {
                if (level)
                    reverse_vector(sub_res);
                res.push_back(sub_res);
                sub_res.clear();
                level = !level;
            }
            if (q.empty()) break;
            q.push(nullptr);
        }
        return res;
    }

private:
    void reverse_vector(vector<int> &v) {
        int n = v.size();
        int tmp = 0;
        for (int i = 0; i < n / 2; i++) {
            tmp = v[i];
            v[i] = v[n - i - 1];
            v[n - i - 1] = tmp;
        }
    }
};
