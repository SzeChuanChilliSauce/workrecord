#include <iostream>

template <typename T>
T add(T a, T b) {
    std::cout << "add<>" << std::endl;
    return a+b;
}
int add2(int a, int b) {
    std::cout << "add" << std::endl;
    return a+b;
}

template <typename T>
void myPrint(T a, T b) {
    std::cout << "template print(T,T)" << std::endl;
}
template <typename T>
void myPrint(T a, T b, T c) {
    std::cout << "template print(T,T,T)" << std::endl;
}
void myPrint(int a, int b) {
    std::cout << "print" << std::endl;
}

int main() {
    int a = 10, b = 20;
    char c = 'c';
    // 模板函数不能进行隐式类型转换
    // add(a, c); // error
    // 普通函数可以进行隐式类型转换
    add2(a, c);

    // 如果出现重载，优先使用普通函数，如果普通函数只有声明没有定义，则报错
    myPrint(a, b);

    // 如果想强制使用模板函数，可以使用空参数列表或指定类型参数
    myPrint<>(a, b);
    myPrint<int>(a, b);

    // 函数模板可以重载
    int d = 30;
    myPrint(a, b, d);

    // 如果函数模板可以产生更好的匹配，那么优先调用函数模板
    char e = 'e';
    myPrint(c, e); // 匹配模板函数

    return 0;
}
