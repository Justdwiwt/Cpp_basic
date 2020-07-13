#include <map>
#include <vector>

using namespace std;

struct Line {
    int x, y, dx, dy;
    int count;
    vector<int> node_indices;

    Line(int _x, int _y, int _dx, int _dy, int _count)
            : x(_x), y(_y), dx(_dx), dy(_dy), count(_count) {}
};

class Solution {
public:
    int maxPoints(vector<vector<int>> &ori_points) {
        for (auto &point : ori_points) ++point_counts[point];
        for (auto &p : point_counts) points.push_back(p.first);
        int N = points.size();
        if (N <= 2) {
            int cnt = 0;
            for (auto &p : point_counts) cnt += p.second;
            return cnt;
        }
        lines.push_back(create(points[0], points[1], point_counts));
        lines[0].node_indices.push_back(0);
        lines[0].node_indices.push_back(1);
        for (int i = 2; i < N; ++i) {
            vector<bool> seen(i, false);
            auto p = points[i];
            int s = lines.size();
            for (int j = 0; j < s; ++j)
                if (onLine(lines[j], p)) {
                    lines[j].count += point_counts[p];
                    lines[j].node_indices.push_back(i);
                } else {
                    for (auto k : lines[j].node_indices)
                        if (!seen[k]) {
                            lines.push_back(create(p, points[k], point_counts));
                            lines.back().node_indices.push_back(i);
                            lines.back().node_indices.push_back(k);
                            seen[k] = true;
                        }
                }
        }
        int res = 2;
        for (auto &line : lines) res = max(res, line.count);
        return res;
    }

private:
    vector<Line> lines;
    vector<vector<int> > points;
    map<vector<int>, int> point_counts;

    static bool onLine(const Line &line, vector<int> &p) {
        return (long) (p[1] - line.y) * (long) line.dx == (long) (p[0] - line.x) * (long) line.dy;
    }

    static Line create(const vector<int> &p1, const vector<int> &p2,
                       map<vector<int>, int> &point_counts) {
        return Line(p1[0], p1[1], p2[0] - p1[0], p2[1] - p1[1],
                    point_counts[p1] + point_counts[p2]);
    }
};
