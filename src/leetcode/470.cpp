#include <cstdlib>

using namespace std;

class Solution {
public:
    static int rand7() {
        return rand() % 7 + 1;
    }

    int rand10() {
        int a = 7 * (rand7() - 1) + rand7();
        while (a > 40) {
            a = 7 * (rand7() - 1) + rand7();
        }
        return a % 10 + 1;
    }
};
