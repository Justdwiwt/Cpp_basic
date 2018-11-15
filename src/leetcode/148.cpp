#include <vector>
#include <algorithm>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
using namespace std;

//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    ListNode *sortList(ListNode *head) {
        ListNode *cur = head;
        vector<int> V;
        while (cur) {
            V.push_back(cur->val);
            cur = cur->next;
        }
        sort(V.begin(), V.end());
        cur = head;
        for (int i : V) {
            cur->val = i;
            cur = cur->next;
        }
        return head;
    }
};

#pragma clang diagnostic pop