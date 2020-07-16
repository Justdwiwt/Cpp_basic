#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int n;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        g = vector<vector<int>>(numCourses, vector<int>());
        in_degree = vector<int>(numCourses, 0);
        for (auto &elem : prerequisites) {
            g[elem[1]].push_back(elem[0]);
            in_degree[elem[0]]++;
        }
        n = numCourses;
        return topological();
    }

private:
    vector<int> in_degree;
    vector<vector<int>> g;

    bool topological() {
        int num = 0;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (in_degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u])
                if (--in_degree[v] == 0) q.push(v);
            num++;
        }
        if (num == n) return true;
        else return false;
    }
};
