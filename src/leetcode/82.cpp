struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return nullptr;
        auto *pre = new ListNode(-1);
        auto *res = new ListNode(-1);
        pre->next = head;
        res = pre;
        while (head->next) {
            int target = head->val;
            if (head->next->val != target) {
                head = head->next;
                pre = pre->next;
            } else {
                auto *post = new ListNode(-1);
                post = head->next;
                while (post->next && post->next->val == target) {
                    post = post->next;
                }
                if (!post->next) {
                    pre->next = nullptr;
                    return res->next;
                } else {
                    head = post->next;
                    pre->next = head;
                }
            }
        }
        return res->next;
    }
};
