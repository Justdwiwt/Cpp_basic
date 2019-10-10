#ifndef CPPTESTPROJECT_BITMAP_H
#define CPPTESTPROJECT_BITMAP_H

#include <iostream>
#include <cstring>

class BitMap {
public:
    BitMap() {
        bitmap = nullptr;
        size = 0;
    }

    BitMap(int size) {
        bitmap = nullptr;
        bitmap = new char[size];
        if (bitmap == nullptr) std::cout << "Error";
        else {
            memset(bitmap, 0x0, size * sizeof(char));
        }
    }

    int initBitMap(int size) {
        bitmap = nullptr;
        bitmap = new char[size];
        if (bitmap == nullptr) {
            std::cout << "Error";
            return 0;
        } else {
            memset(bitmap, 0x0, size * sizeof(char));
            this->size = size;
            return this->size;
        }
    }

    int bitmapSet(int index) {
        int addr = index / 8;
        int addrOffSet = index % 8;
        unsigned char temp = 0x1 << addrOffSet;
        if (addr > (size + 1)) return 0;
        else {
            bitmap[addr] |= temp;
            return 1;
        }
    }

    int bitmapGet(int index) {
        int addr = index / 8;
        int addrOffSet = index % 8;
        unsigned char temp = 0x1 << addrOffSet;
        if (addr > (size + 1)) return 0;
        else return (bitmap[addr] & temp) > 0 ? 1 : 0;
    }

    int bitmapDel(int index) {
        if (bitmapGet(index) == 0) return 0;
        int addr = index / 8;
        int addrOffSet = index % 8;
        unsigned char temp = 0x1 << addrOffSet;
        if (addr > (size + 1)) return 0;
        else {
            bitmap[addr] ^= temp;
            return 1;
        }
    }

private:
    char *bitmap;
    int size;
};

#endif //CPPTESTPROJECT_BITMAP_H
