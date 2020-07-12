#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    explicit Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = std::move(_neighbors);
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) return nullptr;
        if (record.find(node) != record.end()) return record[node];
        Node *res = new Node(node->val);
        record.insert(make_pair(node, res));
        for (Node *iter : node->neighbors)
            res->neighbors.push_back(cloneGraph(iter));
        return res;
    }

private:
    unordered_map<Node *, Node *> record;
};
