#include <bitset>

using namespace std;

class Solution {
public:
    int binaryGap(int N) {

        bitset<31> binary(N);

        bool flag = false;
        int gap = 0;
        int max_gap = 0;

        for (int i = 0; i < binary.size(); i++) {
            if (flag == true && !binary.test(i))
                gap++;

            else if (flag == false && binary.test(i))
                flag = true;

            else if (flag == true && binary.test(i)) {
                gap++;
                flag == false;
                max_gap = max(gap, max_gap);
                gap = 0;
            }
        }
        return max_gap;
    }
};
