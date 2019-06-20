#include <cstdlib>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) return 2147483647;//正整数和负整数最大值差1
        bool flag = 0;
        if (dividend > 0 ^ divisor > 0) flag = 1;//运用异或运算
        long long dvd = labs(dividend);//将dividend和divisor转换为正整数，并赋值给一个long long型
        long long dvs = labs(divisor);//此处一定要用labs，用abs会出错
        long long d = 0;//用来保存结果
        while (dvd >= dvs) {
            long long temp = dvs;
            long long divide = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                divide <<= 1;
            }
            dvd -= temp;//改变被除数的大小
            d += divide;
        }
        return (flag) ? (0 - d) : d;
    }
};
