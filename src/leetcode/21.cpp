struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l;
        ListNode *tmp;
        ListNode *res;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val > l2->val) {
            l = l2;
            l2 = l1;
            l1 = l;
        }
        res = l1;
        while (l2 != nullptr) {
            if (l1 == nullptr) return res;
            if (l1->next == nullptr || l2->val < l1->next->val) {
                l = l1->next;
                tmp = l2->next;
                l1->next = l2;
                l2->next = l;
                l1 = l2;
                l2 = tmp;
            } else l1 = l1->next;
        }
        return res;
    }
};
