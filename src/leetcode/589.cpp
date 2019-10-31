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
    vector<int> preorder(Node *root) {
        vector<int> res;
        func(root, res);
        return res;
    }

private:
    void func(Node *node, vector<int> &res) {
        if (!node) return;
        res.push_back(node->val);
        for (Node *i : node->children) func(i, res);
    }
};
