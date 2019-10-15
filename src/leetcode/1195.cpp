#include <mutex>
#include <functional>

using namespace std;

class FizzBuzz {
private:
    int n;
    mutex mNum, mFizz, mBuzz, mFB;
public:
    explicit FizzBuzz(int n) {
        this->n = n;
        mFizz.lock();
        mBuzz.lock();
        mFB.lock();
    }

    // printFizz() outputs "fizz".
    void fizz(const function<void()> &printFizz) {
        for (int i = 3; i <= n; i += 3) {
            if (i % 5 == 0) continue;
            else {
                mFizz.lock();
                printFizz();
                mNum.unlock();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(const function<void()> &printBuzz) {
        for (int i = 5; i <= n; i += 5) {
            if (i % 3 == 0)continue;
            else {
                mBuzz.lock();
                printBuzz();
                mNum.unlock();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(const function<void()> &printFizzBuzz) {
        for (int i = 15; i <= n; i += 15) {
            mFB.lock();
            printFizzBuzz();
            mNum.unlock();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(const function<void(int)> &printNumber) {
        for (int i = 1; i <= n; i++) {
            mNum.lock();
            if ((i % 3 == 0) && (i % 5 == 0)) mFB.unlock();
            else if (i % 3 == 0) mFizz.unlock();
            else if (i % 5 == 0) mBuzz.unlock();
            else {
                printNumber(i);
                mNum.unlock();
            }
        }
    }
};
