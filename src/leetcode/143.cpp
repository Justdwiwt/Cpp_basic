#include <deque>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head) return;
        deque<ListNode *> dq;
        ListNode *pt = head;
        while (pt) {
            dq.push_back(pt);
            pt = pt->next;
        }
        auto *dummy = new ListNode(-1);
        pt = dummy;
        while (!dq.empty()) {
            pt->next = dq.front();
            dq.pop_front();
            pt = pt->next;
            if (!dq.empty()) {
                pt->next = dq.back();
                dq.pop_back();
                pt = pt->next;
            }
        }
        pt->next = nullptr;
    }
};
