struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        auto *dummy = new ListNode(-1);
        ListNode *p = dummy;
        dummy->next = head;
        for (auto i = 0; i < m - 1; ++i) p = p->next;
        ListNode *cur = p->next;
        for (auto i = m; i < n; ++i) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = p->next;
            p->next = tmp;
        }
        return dummy->next;
    }
};
