#include <iostream>

template<typename NameType, typename AgeType=int>
class Person {
public:
    Person(NameType name, AgeType age) : m_name(name),m_age(age) {}

    void show() {
        std::cout << m_name << " " << m_age << std::endl;
    }

    NameType m_name;
    AgeType m_age;
};

// 指定转入类型
void work(Person<std::string, int>& p) {
    p.show();
}

void test01() {
    Person<std::string, int> p("cdd",123);
    work(p);
}

// 参数模板化
template <typename T1, typename T2>
void work2(Person<T1, T2>& p) {
    std::cout << typeid(T1).name() << std::endl;
    std::cout << typeid(T2).name() << std::endl;
    p.show();
}

void test02() {
    Person<std::string, int> p("Tom", 17);
    work2(p);
}

// 整体模板化
template <typename T>
void work3(T& p) {
    std::cout << typeid(T).name() << std::endl;
    p.show();
}

void test03() {
    Person<std::string, int> p("Trump", 70);
    work3(p);
}


int main() {
    test01();
    test02();
    test03();
    return 0;
}
