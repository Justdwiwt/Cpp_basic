#include <queue>
#include <stdexcept>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() = default;

    queue<int> q1;
    queue<int> q2;

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto res = top();
        q1.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        if (empty()) throw runtime_error("stack is empty");
        if (q1.empty()) swap(q1, q2);
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() const {
        return q1.empty() && q2.empty();
    }
};
