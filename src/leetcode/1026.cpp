#include <vector>
#include <cstdlib>

#define MAX_H 16

using namespace std;

struct Node {
    Node *next;
    Node *down;
    Node *prev;
    int val;
    int cnt;

    Node() : val(-1), next(nullptr), down(nullptr), prev(nullptr), cnt(1) {}

    explicit Node(int val) : val(val), next(nullptr), down(nullptr), prev(nullptr), cnt(1) {}
};

class Skiplist {
public:
    Skiplist() {
        for (int i = 0; i < MAX_H; ++i) dummy.push_back(new Node());
        for (int i = MAX_H - 1; i > 0; --i) dummy[i]->down = dummy[i - 1];
    }

    int height() {
        for (int i = 0; i < MAX_H; ++i)
            if (rand() % 2) return i + 1;
        return MAX_H;

    }

    pair<vector<Node *>, bool> findOrPrev(int val) {
        vector<Node *> p = dummy;
        int top = MAX_H - 1;
        while (top >= 0) {
            while (p[top]->next && p[top]->next->val <= val) p[top] = p[top]->next;
            if (p[top]->val == val) {
                while (top > 0) {
                    p[top - 1] = p[top]->down;
                    top--;
                }
                return {p, true};
            }
            top--;
        }
        return {p, false};
    }

    bool search(int target) {
        auto p = findOrPrev(target);
        return p.second;
    }

    void add(int num) {
        auto p = findOrPrev(num);
        if (p.second) {
            for (int i = 0; i < MAX_H; ++i) {
                if (p.first[i]->val == num) p.first[i]->cnt++;
                else break;
            }
            return;
        }
        int maxH = height();
        for (int i = 0; i < maxH; ++i) {
            Node *newNode = new Node(num);
            newNode->next = p.first[i]->next;
            newNode->prev = p.first[i];
            if (p.first[i]->next) p.first[i]->next->prev = newNode;
            p.first[i]->next = newNode;
        }
        for (int i = maxH - 1; i > 0; --i)
            p.first[i]->next->down = p.first[i - 1]->next;
    }

    bool erase(int num) {
        auto p = findOrPrev(num);
        if (!p.second) return false;
        for (int i = 0; i < MAX_H; ++i) {
            if (p.first[i]->val == num) {
                p.first[i]->cnt--;
                if (p.first[i]->cnt == 0) {
                    p.first[i]->prev->next = p.first[i]->next;
                    if (p.first[i]->next) p.first[i]->next->prev = p.first[i]->prev;
                    delete p.first[i];
                }
            } else break;
        }
        return true;
    }

private:
    vector<Node *> dummy;
};
