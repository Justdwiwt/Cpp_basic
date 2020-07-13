#include <deque>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') ++left;
        while (left <= right && s[right] == ' ') --right;
        while (left <= right) {
            char c = s[left];
            if (!word.empty() && c == ' ') {
                dq.push_front(move(word));
                word = "";
            } else if (c != ' ')word += c;
            ++left;
        }
        dq.push_front(move(word));
        while (!dq.empty()) {
            res += dq.front();
            dq.pop_front();
            if (!dq.empty()) res += ' ';
        }
        return res;
    }

private:
    string res;
    string word;
    deque<string> dq;
};
