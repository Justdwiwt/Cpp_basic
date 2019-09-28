#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int size = citations.size();
        int l = 0;
        int r = size;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (citations[size - mid - 1] >= mid + 1) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
