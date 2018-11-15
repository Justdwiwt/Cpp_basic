#include <string>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
using namespace std;

//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，
//并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
class Solution {
public:
    string toLowerCase(string str) {
        for (char &i : str)
            if ((i >= 'A') && (i <= 'Z'))
                i = i + ('a' - 'A');
        return str;
    }
};

#pragma clang diagnostic pop