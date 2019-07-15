#include <mutex>
#include <functional>

using namespace std;

class H2O {
private:
    int countOxygen;
    pthread_mutex_t lockHy;
    pthread_mutex_t lockOx;
public:
    H2O() {
        pthread_mutex_init(&lockHy, nullptr);
        pthread_mutex_init(&lockOx, nullptr);
        pthread_mutex_lock(&lockOx);
        this->countOxygen = 2;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        pthread_mutex_lock(&lockHy);
        releaseHydrogen();
        this->countOxygen--;
        if (this->countOxygen > 0) {
            pthread_mutex_unlock(&lockHy);
        } else {
            pthread_mutex_unlock(&lockOx);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        pthread_mutex_lock(&lockOx);
        releaseOxygen();
        this->countOxygen = 2;
        pthread_mutex_unlock(&lockHy);
    }
};
