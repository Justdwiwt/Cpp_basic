#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int >> &people) {
        sort(people.begin(), people.end(), [](const pair<int, int> &resA, const pair<int, int> &resB) {
            return resA.first > resB.first || (resA.first == resB.first && resA.second < resB.second);
        });
        vector<pair<int, int>> res(people.size());
        for (auto &i : people) {
            res.insert(res.begin() + i.second, i);
        }
        res.resize(people.size());
        return res;
    }
};
