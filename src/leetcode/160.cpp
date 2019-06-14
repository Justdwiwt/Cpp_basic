struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (nullptr == headA || nullptr == headB) return nullptr;
        if (headA == headB) return headA;
        ListNode *pA = headA;
        ListNode *pB = headB;
        int count = 0;
        while (pA != pB && count < 3) {
            if (pA->next == nullptr) {
                pA = headB;
                count++;
            } else pA = pA->next;
            if (pB->next == nullptr) {
                pB = headA;
                count++;
            } else pB = pB->next;
        }
        if (pA == pB) return pA;
        else return nullptr;
    }
};

