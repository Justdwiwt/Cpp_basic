#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
using namespace std;

//反转一个单链表。
class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

#pragma clang diagnostic pop