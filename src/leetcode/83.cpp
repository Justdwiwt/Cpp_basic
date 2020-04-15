struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *prev = head;
        while (prev->next)
            if (prev->next->val == prev->val) prev->next = prev->next->next;
            else prev = prev->next;
        return head;
    }
};
