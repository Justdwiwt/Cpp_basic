#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int area = 0;
        int r = height.size() - 1;
        int l = 0;
        while (r > l) {
            area = max(area, min(height[l], height[r]) * (r - l));
            if (height[r] > height[l]) ++l;
            else --r;
        }
        return area;
    }
};
