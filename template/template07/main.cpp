#include <iostream>

template <typename T1, typename T2>
class Person {
public:
    Person(T1 name, T2 age) : m_name(name), m_age(age) {}
    void print();
    T1 m_name;
    T2 m_age;
};

// 类外实现类模板成员函数
template <typename T1, typename T2>
void Person<T1,T2>::print() {
    std::cout << m_name << " " << m_age << std::endl;
}

int main() {
    Person<std::string, int> cdd("cdd",123);
    cdd.print();

    return 0;
}
