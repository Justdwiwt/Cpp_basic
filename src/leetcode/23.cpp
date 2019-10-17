#include <vector>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        multimap<int, ListNode *> map;
        for (auto i: lists)
            if (i != nullptr) map.insert(pair<int, ListNode *>(i->val, i));
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (!map.empty()) {
            auto iterator = map.begin();
            tail->next = iterator->second;
            tail = tail->next;
            if (iterator->second->next != nullptr)
                map.insert(pair<int, ListNode *>
                                   (iterator->second->next->val,
                                    iterator->second->next));
            map.erase(iterator);
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
