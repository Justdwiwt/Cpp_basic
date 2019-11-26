#include <utility>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int minStickers(vector<string> &stickers, string target) {
        int N = stickers.size();
        vector<vector<int>> freq(N, vector<int>(26, 0));
        unordered_map<string, int> memo;
        memo[""] = 0;
        for (int i = 0; i < N; ++i) {
            for (char c : stickers[i]) ++freq[i][c - 'a'];
        }
        return helper(freq, std::move(target), memo);
    }

    int helper(vector<vector<int>> &freq, string target, unordered_map<string, int> &memo) {
        if (memo.count(target)) return memo[target];
        int res = INT_MAX, N = freq.size();
        vector<int> cnt(26, 0);
        for (char c : target) ++cnt[c - 'a'];
        for (int i = 0; i < N; ++i) {
            if (freq[i][target[0] - 'a'] == 0) continue;
            string t;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] - freq[i][j] > 0) t += string(cnt[j] - freq[i][j], 'a' + j);
            }
            int ans = helper(freq, t, memo);
            if (ans != -1) res = min(res, ans + 1);
        }
        memo[target] = (res == INT_MAX) ? -1 : res;
        return memo[target];
    }
};