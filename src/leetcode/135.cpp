#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> cd(ratings.size(), 1);
        int sum = 0;
        for (int i = 1; i < ratings.size(); i++)
            if (ratings[i] > ratings[i - 1]) cd[i] = cd[i - 1] + 1;
        for (int i = ratings.size() - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1]) cd[i] = max(cd[i], cd[i + 1] + 1);
        for (int i : cd) sum += i;
        return sum;
    }
};
