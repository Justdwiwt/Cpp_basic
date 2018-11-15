#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

//设计循环队列实现
class MyCircularQueue {
private:
    int *data;
    int head;
    int tail;
    int len;
    int count;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    explicit MyCircularQueue(int k) {
        data = new int[k];
        head = 0;
        tail = 0;
        len = k;
        count = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        else {
            data[tail] = value;
            count++;
            tail = (tail + 1) % len;
            return true;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        else {
            head = (head + 1) % len;
            count--;
            return true;
        }
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        else return data[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        else {
            int tmp = tail == 0 ? (len - 1) : (tail - 1);
            return data[tmp];
        }
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return count == len;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
#pragma clang diagnostic pop