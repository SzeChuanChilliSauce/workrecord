#include <iostream>

class Person {
public:
    Person(std::string name, int age)
        : m_name(name), m_age(age) {}

    std::string m_name;
    int m_age;
};

template <typename T> bool compare(T& a, T& b) {
    return a >= b;
}
// 具体化类型
// 如果具体化能优先匹配，就选择具体化
template <> bool compare<Person>(Person&a, Person&b) {
    return a.m_age >= b.m_age;
}

int main() {
    int a = 10, b = 20;
    std::cout << compare(a, b) << std::endl;

    Person p1("cdd", 31);
    Person p2("tom", 12);
    std::cout << compare(p1, p2) << std::endl;

    return 0;
}
