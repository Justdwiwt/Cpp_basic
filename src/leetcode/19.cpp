#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        vector<ListNode *> res;
        while (head->next != nullptr) {
            res.push_back(head);
            head = head->next;
        }
        res.push_back(head);
        res.erase(res.begin() + res.size() - n);
        if (res.empty()) return nullptr;
        for (int i = 0; i < res.size() - 1; ++i) res[i]->next = res[i + 1];
        res[res.size() - 1]->next = nullptr;
        return res[0];
    }
};
