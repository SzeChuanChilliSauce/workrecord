#ifndef TEMPLATE08_PERSON_HPP
#define TEMPLATE08_PERSON_HPP

#include <iostream>
#include <string>

template <typename T1, typename T2>
class Person {
public:
    Person(T1 name, T2 age);
    void show();
    T1 m_name;
    T2 m_age;
};

template <typename T1,typename T2>
Person<T1,T2>::Person(T1 name, T2 age) : m_name(name), m_age(age) {}

template <typename T1, typename T2>
void Person<T1,T2>::show() {
    std::cout << m_name << " " << m_age<< std::endl;
}

#endif //TEMPLATE08_PERSON_HPP
