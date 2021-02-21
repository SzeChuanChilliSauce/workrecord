#include <iostream>
#include <cstdint>

//////模板元编程
//////////////////////////////////////////////////////////////////////
// 计算阶乘
// N!=N*(N-1)*...*1
template<uint64_t N>
struct Fact {
    enum {
        Value = N * Fact<N-1>::Value
    };
};
template <>
struct Fact<1> {
    enum {
        Value = 1
    };
};

// inline
constexpr uint64_t fact(uint64_t n) {
    if (n == 1) return n;
    return n * fact(n-1);
}

// 计算斐波那契数列
// F(1)=1, F(2)=1, F(n)=F(n-1)+F(n-2)
template<uint64_t N>
struct Fib {
    enum {
        Value = Fib<N-1>::Value + Fib<N-2>::Value
    };
};
template <>
struct Fib<2> {
    enum {
        Value = 1
    };
};
template <>
struct Fib<1> {
    enum {
        Value = 1
    };
};

constexpr uint64_t fib(uint64_t n) {
    if (n <= 2) return 1;
    return fib(n-1) + fib(n-2);
}

constexpr uint64_t fib2(uint64_t n) {
    uint64_t f1 = 1, f2 = 1;
    if (n <= 2) return 1;

    uint64_t i = 2;
    uint64_t fi = 0;
    while (i < n) {
        fi = f1 + f2;
        f1 = f2;
        f2 = fi;
        i++;
    }

    return fi;
}

// 实现pow函数
template <uint64_t base, uint64_t exp>
struct POW {
    enum {
        Value = base * POW<base, exp-1>::Value
    };
};
template <uint64_t base>
struct POW<base, 0> {
    enum {
        Value = 1
    };
};
//////////////////////////////////////////////////////////////////////
int main() {
    auto fa = Fact<15>::Value;
    std::cout << fa << std::endl;
    constexpr auto fa2 = fact(15);
    std::cout << fa2 << std::endl;

    auto fi = Fib<10>::Value;
    std::cout << fi << std::endl;
    std::cout << fi << std::endl;
    auto fi2 = fib(98);
    std::cout << "fib2:"<< fi2 << std::endl;
    auto fi3 = fib2(98);
    std::cout << "fib3:"<< fi3 << std::endl;

    auto pow = POW<2, 10>::Value;
    std::cout << pow << std::endl;
    return 0;
}

