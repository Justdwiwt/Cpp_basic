#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() = default;

    Node(int _val, Node *_left, Node *_right, Node *_next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node *connect(Node *root) {
        queue<Node *> q;
        if (!root) return nullptr;
        q.push(root);
        Node *preNode = nullptr;
        while (!q.empty()) {
            int len = q.size();
            preNode = nullptr;
            for (int i = 0; i < len; i++) {
                Node *n = q.front();
                q.pop();
                if (preNode != nullptr) preNode->next = n;
                preNode = n;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return root;
    }
};
