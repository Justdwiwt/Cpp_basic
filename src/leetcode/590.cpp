#include <utility>
#include <vector>

using namespace std;

class Node {
public:
    int val{};
    vector<Node *> children;

    Node() = default;

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = std::move(_children);
    }
};

class Solution {
public:
    vector<int> postorder(Node *root) {
        vector<int> res;
        func(root, res);
        return res;
    }

private:
    void func(Node *node, vector<int> &res) {
        if (!node) return;
        for (Node *i : node->children) func(i, res);
        res.push_back(node->val);
    }
};
