#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */

    stack<int> s1, s2;

    MyQueue() = default;

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(x);
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int a = s2.top();
        s2.pop();
        return a;
    }

    /** Get the front element. */
    int peek() {
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() const {
        return s2.empty();
    }
};
