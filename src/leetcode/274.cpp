#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        vector<int> hash;
        int n = citations.size();
        if (n == 0) return 0;
        if (n == 1) return citations[0] >= 1 ? 1 : 0;
        for (int i = 0; i < n; ++i) {
            while (hash.size() < citations[i] + 1)
                hash.push_back(0);
            hash[citations[i]]++;
        }
        int m = hash.size();
        int count = 0;
        for (int i = m - 1; i >= 0; --i) {
            count += hash[i];
            if (count >= i) return i;
        }
        return 1;
    }

private:
    int solution2(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size();
        for (int i = 0; i < size; ++i)
            if (citations[i] >= size - i)
                return size - i;
        return 0;
    }
};
