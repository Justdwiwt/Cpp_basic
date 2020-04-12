struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        int len = 1;
        ListNode *tail = head;
        while (tail->next) {
            ++len;
            tail = tail->next;
        }
        tail->next = head;
        if (k %= len) for (int i = 0; i < len - k; ++i) tail = tail->next;
        ListNode *res = tail->next;
        tail->next = nullptr;
        return res;
    }
};
