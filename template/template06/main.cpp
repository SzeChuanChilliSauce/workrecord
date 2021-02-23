#include <iostream>

template <typename T>
class Base {
public:
    Base(T b) :m_base(b){}
    T m_base;
};

// Child继承必须指定Base中T，否则无法分配内存
class Child : public Base<int> {
public:

};

template <typename T1, typename T2=double>
class Child2 : public Base<T2> {
public:
    Child2(T1 c, T2 b) : m_c(c), Base<T2>(b) {
        std::cout << typeid(T1).name() << std::endl;
        std::cout << typeid(T2).name() << std::endl;
    }

    void print() {
        // 模板子类中无法直接访问父类的成员，加this->或Base<T>::
        std::cout << Base<T2>::m_base << std::endl;
        std::cout << this->m_base << std::endl;
        std::cout << m_c << std::endl;
    }

    T1 m_c;
};

void test() {
    Child2<int, double> c2(10, 2.13);
    c2.print();
}

int main() {
    test();
    return 0;
}
