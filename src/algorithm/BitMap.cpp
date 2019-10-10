#include "BitMap.h"

template<class Type>
class BloomFilter {
public:
    BloomFilter();

    BloomFilter(int length) {
        bitMap.initBitMap(length);
        this->length = length;
    }

    bool Add(const Type &T);

    bool Contains(const Type &T);

    int Hash(const Type &T);

    int SecondHash(const Type &T);

private:
    BitMap bitMap;
    int length;
};

template<class Type>
int BloomFilter<Type>::Hash(const Type &T) {
    int temp = (int) T;
    return temp % length;
}

template<class Type>
int BloomFilter<Type>::SecondHash(const Type &T) {
    int temp = (int) T;
    return temp % 9973;
}

template<class Type>
bool BloomFilter<Type>::Add(const Type &T) {
    int first = Hash(T);
    int second = SecondHash(first);
    return bitMap.bitmapSet(first) && bitMap.bitmapSet(second) ? true : false;
}

template<class Type>
bool BloomFilter<Type>::Contains(const Type &T) {
    int first = Hash(T);
    int second = SecondHash(first);
    return bitMap.bitmapGet(first) && bitMap.bitmapGet(second) ? true : false;
}
