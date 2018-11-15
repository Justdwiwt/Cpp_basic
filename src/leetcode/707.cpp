#include <cstdlib>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

//设计链表的实现
class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        LinkedList = nullptr;
    }

    ListNode *LinkedList;

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i = 0;
        ListNode *head = LinkedList;
        while (head && i < index) {
            head = head->next;
            i++;
        }
        if (head && i == index) return head->val;
        else return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto *head = (ListNode *) malloc(sizeof(ListNode));
        head->next = LinkedList;
        head->val = val;
        LinkedList = head;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *head = LinkedList;
        auto *tmp = (ListNode *) malloc(sizeof(ListNode));
        tmp->next = nullptr;
        tmp->val = val;
        if (!head) {
            LinkedList = tmp;
            return;
        }
        while (head->next)
            head = head->next;
        head->next = tmp;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int i = 0;
        ListNode *head = LinkedList;
        if (!head && index == 0) {
            auto *tmp = (ListNode *) malloc(sizeof(ListNode));
            tmp->val = val;
            tmp->next = nullptr;
            LinkedList = tmp;
            return;
        }
        while (head && i < index - 1) {
            head = head->next;
            i++;
        }
        if (head && head->next == nullptr) {
            auto *tmp = (ListNode *) malloc(sizeof(ListNode));
            tmp->val = val;
            tmp->next = nullptr;
            head->next = tmp;
        } else if (i == index - 1 && head && head->next) {
            auto *tmp = (ListNode *) malloc(sizeof(ListNode));
            tmp->val = val;
            tmp->next = head->next;
            head->next = tmp;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode *head = LinkedList;
        int i = 0;
        while (head && i < index - 1) {
            head = head->next;
            i++;
        }
        if (head == nullptr) return;
        if (head->next == nullptr && index == 0) {
            LinkedList = nullptr;
            return;
        }
        if (head->next) {
            ListNode *tmp = head->next;
            head->next = tmp->next;
            free(tmp);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
#pragma clang diagnostic pop