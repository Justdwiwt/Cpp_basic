#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    double val{};
    Node *parent;

    Node() : parent(this) {}

    explicit Node(double v) : val(v), parent(this) {}
};

Node *find(Node *node) {
    while (node != node->parent)
        node = node->parent;
    return node;
}

void union_(Node *a, Node *b, double num, unordered_map<string, Node *> &map) {
    Node *f1 = find(a);
    Node *f2 = find(b);
    double ratio = b->val * num / a->val;
    for (const auto &n: map)
        if (f1 == find(n.second)) n.second->val *= ratio;
    f1->parent = f2;
}

class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        vector<double> ans;
        unordered_map<string, Node *> map;
        for (int i = 0; i != equations.size(); ++i) {
            if (map.find(equations[i][0]) == map.end())
                map[equations[i][0]] = new Node(values[i]);
            if (map.find(equations[i][1]) == map.end())
                map[equations[i][1]] = new Node(1.0);
            Node *a = map[equations[i][0]];
            Node *b = map[equations[i][1]];
            union_(a, b, values[i], map);
        }
        for (int i = 0; i != queries.size(); ++i)
            if (map.find(queries[i][0]) != map.end() && map.find(queries[i][1]) != map.end()) {
                Node *f1 = find(map[queries[i][0]]);
                Node *f2 = find(map[queries[i][1]]);
                ans.push_back(f1 == f2 ? map[queries[i][0]]->val / map[queries[i][1]]->val : -1.0);
            } else ans.push_back(-1.0);
        return ans;
    }
};
