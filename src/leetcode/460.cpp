#include <map>

using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (dataMap.find(key) == dataMap.end())
            return -1;
        Node *p = dataMap[key];
        NodeList *h = headMap[p->num];
        updateNode(p, h);
        return p->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
        if (dataMap.find(key) != dataMap.end()) {
            Node *p = dataMap[key];
            NodeList *h = headMap[p->num];
            p->val = value;
            updateNode(p, h);
        } else {
            if (dataMap.size() >= this->capacity)
                deleteData();
            Node *p = new Node(key, value, 1);
            dataMap[key] = p;
            if (headMap.find(1) == headMap.end())
                createNode(p, headList);
            else
                moveNode(p, headMap[1]);
        }
    }

private:
    struct Node {
        int key;
        int val;
        int num;
        Node *next;
        Node *pre;

        Node(int a, int b, int n) : key(a), val(b), num(n), next(nullptr), pre(nullptr) {}
    };

    struct NodeList {
        int num;
        Node *head;
        Node *tail;
        NodeList *next;
        NodeList *pre;

        explicit NodeList(int a) : num(a), next(nullptr), pre(nullptr) {
            head = new Node(0, 0, a);
            tail = head;
        }
    };

private:
    static void getNode(Node *&p, NodeList *&h) {
        p->pre->next = p->next;
        if (p->next == nullptr)
            h->tail = p->pre;
        else
            p->next->pre = p->pre;
    }

    static void moveNode(Node *&p, NodeList *&q) {
        p->next = q->tail->next;
        q->tail->next = p;
        p->pre = q->tail;
        q->tail = p;
    }

    void deleteNode(int num, NodeList *&h) {
        headMap.erase(num);
        h->pre->next = h->next;
        if (h->next != nullptr)
            h->next->pre = h->pre;
        delete h;
        h = nullptr;
    }

    void createNode(Node *p, NodeList *&h) {
        NodeList *q = new NodeList(p->num);
        headMap[p->num] = q;
        moveNode(p, q);
        q->next = h->next;
        if (h->next != nullptr)
            h->next->pre = q;
        h->next = q;
        q->pre = h;
    }

    void updateNode(Node *&p, NodeList *&h) {
        int num = p->num;
        p->num++;
        getNode(p, h);
        if (headMap.find(p->num) == headMap.end())
            createNode(p, h);
        else
            moveNode(p, headMap[p->num]);
        if (h->head == h->tail)
            deleteNode(num, h);
    }

    void deleteData() {
        NodeList *p = headList->next;
        Node *q = p->head->next;
        if (q == p->tail)
            deleteNode(q->num, p);
        else {
            p->head->next = q->next;
            q->next->pre = p->head;
        }
        dataMap.erase(q->key);
        delete q;
        q = nullptr;
    }

private:
    int capacity;
    NodeList *headList = new NodeList(0);
    map<int, Node *> dataMap;
    map<int, NodeList *> headMap;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
