struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *pRet = nullptr, *pFirst = nullptr;
        int nAdd = 0, nSum = 0;
        while (l1 || l2) {
            nSum = nAdd;
            if (l1) {
                nSum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                nSum += l2->val;
                l2 = l2->next;
            }
            nAdd = nSum > 9;
            auto pNew = new ListNode(nSum % 10);
            if (pFirst)
                pFirst = pFirst->next = pNew;
            else
                pFirst = pRet = pNew;
        }
        if (nAdd)
            pFirst->next = new ListNode(1);
        return pRet;
    }
};
