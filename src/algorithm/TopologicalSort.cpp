#include <queue>
#include <list>
#include <iostream>

using namespace std;

class Graph {

    int v;
    list<int> *adj;
    queue<int> q;
    int *deep;

public:
    Graph(int v);

    ~Graph();

    void addEdge(int v, int w);

    bool topological_sort();
};


Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v];

    for (int i = 0; i < v; ++i) deep[i] = 0;
}

Graph::~Graph() {
    delete[] adj;
    delete[] deep;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    ++deep[w];
}

bool Graph::topological_sort() {
    for (int i = 0; i < v; ++i)
        if (deep[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();

        cout << top << " ";
        ++count;

        auto beg = adj[top].begin();
        for (; beg != adj[top].end(); ++beg)
            if (!(-deep[*beg])) q.push(*beg);
    }

    return count < v ? false : true;
}
