#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

template <typename T1, typename T2> class Person;
template <typename T1, typename T2> void printPerson3(Person<T1, T2>& p);

template <typename T1, typename T2>
class Person {
public:
    Person(T1 name, T2 age) : m_name(name), m_age(age) {}
    // 友元函数类内实现
    friend void printPerson(Person<T1, T2>& p) {
        std::cout << "printPerson(): " <<  p.m_name << " " << p.m_age << std::endl;
    }
    // 普通函数声明
    friend void printPerson2(Person<T1, T2>& p);
    // 利用空参列表，告诉编译器是模板函数声明
    friend void printPerson3<>(Person<T1, T2>& p);
private:
    T1 m_name;
    T2 m_age;
};

// 友元函数类外实现
template <typename T1, typename T2>
void printPerson3(Person<T1, T2>& p) {
    std::cout << "printPerson2(): " << p.m_name << " " << p.m_age << std::endl;
}


int main() {
    Person<std::string, int> cdd("cdd", 123);
    printPerson(cdd);
    printPerson3(cdd);
    return 0;
}

