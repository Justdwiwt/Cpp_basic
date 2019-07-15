#include <iostream>
#include <mutex>
#include <functional>

using namespace std;

class Foo {
public:
    mutex smx;
    mutex tmx;

    Foo() {
        smx.lock();
        tmx.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        smx.unlock();
    }

    void second(function<void()> printSecond) {
        lock_guard<mutex> lg(smx);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        tmx.unlock();
    }

    void third(function<void()> printThird) {
        lock_guard<mutex> lg(tmx);
        lock_guard<mutex> lg1(smx);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
