struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        auto *before = new ListNode(0);
        auto *after = new ListNode(0);
        ListNode *p1 = before, *p2 = after;
        if (!head) return head;
        while (head)
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
                head = head->next;
            } else {
                p2->next = head;
                p2 = p2->next;
                head = head->next;
            }
        p2->next = nullptr;
        p1->next = after->next;
        return before->next;
    }
};
