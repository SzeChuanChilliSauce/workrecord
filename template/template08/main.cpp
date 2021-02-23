#include <iostream>
#include "Person.hpp"


//建议不要做分文件编写，写到一个类中即可，类内进行声明和实现，最后吧后缀名改为.hpp
//#include "Person.h"
//#include "Person.cpp"


int main() {
    Person<std::string, int> cdd("cdd",123);
    cdd.show();

    return 0;
}
