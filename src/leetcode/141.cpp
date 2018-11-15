#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "google-explicit-constructor"

#include <vector>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
using namespace std;

//给定一个链表，判断链表中是否有环。
class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    bool hasCycle(ListNode *head) {
        ListNode *left = head, *right = head;
        while (right && right->next && right->next->next) {
            left = left->next;
            right = right->next->next;
            if (left == right) return true;
        }
        return false;
    }
};

#pragma clang diagnostic pop
#pragma clang diagnostic pop