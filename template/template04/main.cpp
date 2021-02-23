#include <iostream>

//类模板可以有默认参数
template <typename NameType, typename AgeType=int>
class Person {
public:
    Person(NameType name, AgeType age)
        : m_name(name), m_age(age) {}

    void show() {
        std::cout << m_name << " " << m_age << std::endl;
    }

    NameType m_name;
    AgeType m_age;
};

void test01() {
    // 类模板不支持自动类型推导
    // Person p("cdd", 100); // error
    // 显式指定类型
    Person<std::string, int> p("cdd",123);
    Person<std::string> p2("bdd",321);
    p.show();
    p2.show();
}


class Person1 {
public:
    void showPerson1() {
        std::cout << "showPerson1" << std::endl;
    }
};

class Person2 {
public:
    void showPerson2() {
        std::cout << "showPerson2()" << std::endl;
    }
};

template <typename T>
class MyClass {
public:
    T obj;
    void fn1() {
        obj.showPerson1();
    }
    void fn2() {
        obj.showPerson2();
    }
};

// 成员函数一开始不会创建出来，而是在运行时才去创建
void test02() {
    MyClass<Person1> m;
    m.fn1();
}

int main() {
    test01();
    return 0;
}
