#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr)return nullptr;
        else if (head->next == nullptr)return new TreeNode(head->val);
        else if (head->next->next == nullptr) {
            auto *root = new TreeNode(head->next->val);
            root->left = new TreeNode(head->val);
            return root;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        auto *root = new TreeNode(slow->val);
        pre->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
