#include <iostream>

void swapInt(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swapDouble(double& a, double& b) {
    double tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void swap(T& a,T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void swap2() {}

// 对char和int数组进行从达到小进行选择排序
template <typename T>
void sort(T* arr, int len) {
    for (int i = 0; i < len; i++) {
        int max = i;
        for (int j = i+1; j < len; j++ ) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        if (max != i) {
            swap(arr[i], arr[max]);
        }
    }
}

template<typename T>
void printArr(T* arr, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void test() {
    char charArr[] = "helloworld";
    int len = sizeof(charArr)/sizeof(char);
    sort(charArr, len);
    printArr(charArr, len);

    int intArr[] = {2,1,34,12,48,11,100};
    len = sizeof(intArr)/sizeof(int);
    sort(intArr, len);
    printArr(intArr, len);
}

int main() {
    int a = 10;
    int b = 20;
    char c = 'a';
    swapInt(a, b);
    std::cout << a << " " << b << std::endl;

    double da = 1.23;
    double db = 3.45;
    swapDouble(da, db);
    std::cout << da << " " << db << std::endl;

    // 自动类型推导，必须能确定参数类型才能推导
    // swap(a, c); // error
    swap(a, b);
    std::cout << a << " " << b << std::endl;

    // 显式指定类型
    swap<int>(a, b);
    std::cout << a << " " << b << std::endl;
    // 告诉编译器调用模板函数 
    swap<>(a,b);
    std::cout << a << " " << b << std::endl;

    // 模板必须要指定T才能使用
    swap2<double>();

    swap(da, db);
    std::cout << da << " " << db << std::endl;

    test();

    return 0;
}






