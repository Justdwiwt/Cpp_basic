struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode *pre = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *s = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = s;
            s = pre;
        }
        ListNode *tmp = slow;
        if (fast != nullptr) tmp = tmp->next;
        slow = pre;
        while (tmp != nullptr) {
            if (tmp->val != slow->val)return false;
            else {
                tmp = tmp->next;
                slow = slow->next;
            }
        }
        return true;
    }
};
