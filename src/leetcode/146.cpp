#include <unordered_map>
#include <list>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
using namespace std;

class LRUCache {
private:
    int cap;
    int count;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int >> queue;

public:
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
    }

    int get(int key) {
        int res = -1;
        auto p = m.find(key);
        if (p != m.end()) {
            res = p->second->second;
            queue.erase(p->second);
            queue.push_front(make_pair(key, res));
            p->second = queue.begin();
        }
        return res;
    }

    void put(int key, int value) {
        auto p = m.find(key);
        if (p != m.end()) {
            queue.erase(p->second);
        } else if (count == cap) {
            int delKey = queue.back().first;
            queue.pop_back();
            m.erase(delKey);
        } else {
            ++count;
        }
        queue.push_front(make_pair(key, value));
        m[key] = queue.begin();
    }
};

#pragma clang diagnostic pop