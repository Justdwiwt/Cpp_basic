struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *pSlow = head;
        ListNode *pFast = head;
        while (pFast && pFast->next) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if (pSlow == pFast) break;
        }
        if (!pFast || !pFast->next) return nullptr;
        pSlow = head;
        while (pSlow != pFast) {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pFast;
    }
};
