bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int pLeft = 1;
        int pRight = n;
        while (pLeft < pRight) {
            int mid = pLeft + (pRight - pLeft) / 2;
            isBadVersion(mid) ? (pRight = mid) : (pLeft = mid + 1);
        }
        return pRight;
    }
};
