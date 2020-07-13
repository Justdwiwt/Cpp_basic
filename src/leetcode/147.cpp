//
// Created by 段泽宇 on 2020/7/13.
//
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) return head;
        auto *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode *prev = head;
        ListNode *node = head->next;
        while (node) {
            if (node->val < prev->val) {
                ListNode *temp = dummy_head;
                while (temp->next->val < node->val) temp = temp->next;
                prev->next = node->next;
                node->next = temp->next;
                temp->next = node;
                node = prev->next;
            } else {
                prev = prev->next;
                node = node->next;
            }
        }
        return dummy_head->next;
    }
};
