# LeetCode

## lambda捕获

``` cpp
static const auto init = []() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;

}();
```

### lambda

> 是`C++ 11`引入的特性，一种描述函数对象的机制，也称为匿名函数。

``` cpp
static const auto io_sync_off = []() {
    ...
}();
```

等价于

``` cpp
static const auto function() {
    ...
}
```

**`std:ios::sync_with_stdio(false);`**

> 设置在每次io操作后，标准C++流是否与标准C流同步。

在C++中，`std::cin`和`std:out`为了兼容C，保证代码中同时出现`std::cin`和`scanf`或`std::out`和`printf`时输出不发生混乱，所以C++使用一个**流缓冲区**来同步C的标准流。
通过`std::ios_base::sync_with_stdio`函数可以**解除这种同步**，让`std::cin`和`std::out`不再经过缓冲区，达到节省时间的效果。

**`std::cin.tie(nullptr);`**

因为`std::cin`和`std:out` **默认绑定**，每次操作的时候（调用`<<`或`>>`）都要刷新（调用`flush`），这样增加了IO负担。
通过`tie(nullptr)`来解除`std::cin`和`std:out`之间的绑定，来降低IO的负担使效率提升。

* 使用`std::ios::sync_with_stdio(false)`和`std::cin.tie(nullptr)`之后要避免和`scanf`和`printf`混用以避免出现问题。

### 声明Lambda表达式

Lambda表达式完整的声明格式如下：

``` cpp
[capture list] (params list) mutable exception-> return type { function body }
```

各项具体含义如下:

1. `capture list`：捕获外部变量列表
2. `params list`：形参列表
3. `mutable`指示符：用来说用是否可以修改捕获的变量
4. `exception`：异常设定
5. `return type`：返回类型
6. `function body`：函数体

常见的省略参数的lambda表达式：

``` cpp
[capture list] (params list) -> return type {function body}
```

* 声明了`const`类型的表达式，这种类型的表达式**不能修改捕获列表中的值**。

``` cpp
[capture list] (params list) {function body}
```

* 省略了返回值类型，但编译器可以根据以下规则推断出Lambda表达式的返回类型：
    * 如果`function body`中存在`return`语句，则该Lambda表达式的返回类型由`return`语句的返回类型确定.
    * 如果`function body`中没有`return`语句，则返回值为`void`类型。

``` cpp
[capture list] {function body}
```

* 省略了参数列表，类似普通函数中的无参函数。

**实例**

``` cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return  a < b;
}

int main() {
    vector<int> myvec{ 3, 2, 5, 7, 3, 2 };
    vector<int> lbvec(myvec);

    sort(myvec.begin(), myvec.end(), cmp); // 旧式做法
    cout << "predicate function:" << endl;
    for (int it : myvec)
        cout << it << ' ';
    cout << endl;

    sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool { return a < b; });   // Lambda表达式
    cout << "lambda expression:" << endl;
    for (int it : lbvec)
        cout << it << ' ';
}
```

在C++11之前，使用`STL`的`sort`函数，需要提供一个谓词函数。如果使用C++11的Lambda表达式，我们只需要传入一个匿名函数即可，方便简洁，而且代码的可读性也比旧式的做法好多了。

### 捕获外部变量

Lambda表达式可以使用其可见范围内的外部变量，但必须明确声明（明确声明哪些外部变量可以被该Lambda表达式使用）。
Lambda表达式通过在最前面的方括号[]来明确指明其内部可以访问的外部变量，这一过程也称过Lambda表达式“捕获”了外部变量。

**实例**

``` cpp
#include <iostream>
using namespace std;

int main() {
    int a = 123;
    auto f = [a] { cout << a << endl; }; 
    f(); // 输出：123

    //或通过“函数体”后面的‘()’传入参数
    auto x = [](int a){cout << a << endl;}(123); 
}
```

上面这个例子先声明了一个整型变量a，然后再创建Lambda表达式，该表达式“捕获”了a变量，这样在Lambda表达式函数体中就可以获得该变量的值。

类似参数传递方式（值传递、引入传递、指针传递），在Lambda表达式中，外部变量的捕获方式也有**值捕获**、**引用捕获**、**隐式捕获**。

#### 值捕获

值捕获和参数传递中的值传递类似，被捕获的变量的值在Lambda表达式创建时通过**值拷贝**的方式传入。
因此随后对该变量的修改**不会影响**Lambda表达式中的值。

**实例**

``` cpp
int main() {
    int a = 123;
    auto f = [a] { cout << a << endl; }; 
    a = 321;
    f(); // 输出：123
}
```

* 如果以传值方式捕获外部变量，则在Lambda表达式函数体中不能修改该**外部变量**的值。

#### 引用捕获

使用引用捕获一个外部变量，只需要在捕获列表变量前面加上一个引用说明符`&`。

**实例**

``` cpp
int main() {
    int a = 123;
    auto f = [&a] { cout << a << endl; }; 
    a = 321;
    f(); // 输出：321
}
```

* 引用捕获的变量使用的实际上就是该引用所**绑定的对象**。

#### 隐式捕获

值捕获和引用捕获都需要在捕获列表中显示列出Lambda表达式中使用的外部变量。
除此之外，还可以让编译器根据函数体中的代码来推断需要捕获哪些变量，这种方式称之为隐式捕获。

隐式捕获有两种方式，分别是`[=]`和`[&]`。
`[=]`表示以**值捕获**的方式捕获外部变量，`[&]`表示以**引用捕获**的方式捕获外部变量。

**隐式值捕获**

``` cpp
int main() {
    int a = 123;
    auto f = [=] { cout << a << endl; };    // 值捕获
    f(); // 输出：123
}
```

**隐式引用捕获**

``` cpp
int main() {
    int a = 123;
    auto f = [&] { cout << a << endl; };    // 引用捕获
    a = 321;
    f(); // 输出：321
}
```

#### 混合方式

| 捕获形式    | 说明                                                                                    |
| :---------- | :-------------------------------------------------------------------------------------- |
| []          | 不捕获任何外部变量                                                                      |
| [变量名, …] | 默认以值得形式捕获指定的多个外部变量（用逗号分隔），如果引用捕获，需要显示声明（使用&） |
| [this]      | 以值的形式捕获this指针                                                                  |
| [=]         | 以值的形式捕获所有外部变量                                                              |
| [&]         | 以引用形式捕获所有外部变量                                                              |
| [=, &x]     | 变量x以引用形式捕获，其余变量以传值形式捕获                                             |
| [&, x]      | 变量x以值的形式捕获，其余变量以引用形式捕获                                             |

### 修改捕获变量

> 使用`mutable`关键字，该关键字用以说明表达式体内的代码可以修改值捕获的变量。

**实例**

``` cpp
int main() {
    int a = 123;
    auto f = [a]()mutable { cout << ++a; }; // 不会报错
    cout << a << endl; // 输出：123
    f(); // 输出：124
}
```

### Lambda表达式的参数

在Lambda表达式中传递参数还有一些限制，主要有以下几点：

1. 参数列表中不能有默认参数
2. 不支持可变参数
3. 所有参数必须有参数名

**实例**

``` cpp
{
    int m = [](int x) { return [](int y) { return y * 2; }(x)+6; }(5);
    std::cout << "m:" << m << std::endl;            　　//输出m:16

    std::cout << "n:" << [](int x, int y) { return x + y; }(5, 4) << std::endl;            //输出n:9
        
    auto gFunc = [](int x) -> function<int(int)> { return [=](int y) { return x + y; }; };
    auto lFunc = gFunc(4);
    std::cout << lFunc(5) << std::endl;

    auto hFunc = [](const function<int(int)>& f, int z) { return f(z) + 1; };
    auto a = hFunc(gFunc(7), 8);

    int a = 111, b = 222;
    auto func = [=, &b]()mutable { a = 22; b = 333; std::cout << "a:" << a << " b:" << b << std::endl; };

    func();
    std::cout << "a:" << a << " b:" << b << std::endl;

    a = 333;
    auto func2 = [=, &a] { a = 444; std::cout << "a:" << a << " b:" << b << std::endl; };
    func2();

    auto func3 = [](int x) ->function<int(int)> { return [=](int y) { return x + y; }; };

    
　　 std::function<void(int x)> f_display_42 = [](int x) { print_num(x); };
	f_display_42(44);
　　}
```
