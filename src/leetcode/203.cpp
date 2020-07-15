struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *tmp = head;
        ListNode *pre = nullptr;
        while (tmp) {
            if (head == tmp && tmp->val == val) {
                tmp = tmp->next;
                delete head;
                head = tmp;
            } else if (tmp->val == val) {
                pre->next = pre->next->next;
                delete tmp;
                tmp = pre->next;
            } else {
                pre = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};
