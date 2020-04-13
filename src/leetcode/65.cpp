#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool has_dot = false;
        bool has_e = false;
        bool has_front_num = false;
        int i = 0;
        while (s[i] == ' ') ++i;
        if (s[i] == '.') has_dot = true;
        else if (s[i] >= '0' && s[i] <= '9') has_front_num = true;
        else if (s[i] != '+' && s[i] != '-') return false;
        ++i;
        while (i < s.size() &&
               ((s[i] >= '0' && s[i] <= '9') ||
                (has_front_num && !has_e && s[i] == 'e') ||
                (!has_e && !has_dot && s[i] == '.'))) {
            if (s[i] == 'e') {
                has_e = true;
                ++i;
                break;
            } else if (s[i] == '.') has_dot = true;
            else has_front_num = true;
            ++i;
        }
        if (has_e) {
            if (i >= s.size()) return false;
            bool has_tail_num = false;
            if (s[i] >= '0' && s[i] <= '9') has_tail_num = true;
            else if (s[i] != '-' && s[i] != '+') return false;
            ++i;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                has_tail_num = true;
                ++i;
            }
            if (!has_tail_num) return false;
        }
        while (i < s.size() && s[i] == ' ') ++i;
        return has_front_num && i >= s.size();
    }
};
