#include <iostream>
#include <memory>

class A {
public:
    A(int n) : i(n) { }

    ~A() {
        std::cout << "~A():"<< i << std::endl;
    }

    int i;
};

int main() {
    std::shared_ptr<A> p1(new A(1)); //计数加1，计数为1
    std::shared_ptr<A> p2(p1); //计数加1，计数为2
    std::shared_ptr<A> p3;
    p3 = p2; // 计数加1，计数为3
    std::cout << p1->i << " " << p2->i << " " << p3->i << std::endl;


    A* p = p3.get();
    std::cout << p->i << std::endl;


    p1.reset(new A(3)); // p1消亡，计数减1，计数为2
    p2.reset(new A(4)); // p2消亡，计数减1，计数为1
    std::cout << "-------------" << std::endl;
    p3.reset(new A(5)); // p2消亡，计数减1，计数为0，析构
    std::cout << "--------------" << std::endl;
    return 0;
}
