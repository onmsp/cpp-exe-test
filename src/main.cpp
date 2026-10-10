#include <iostream>

#include "calc.h"

#ifndef APP_VERSION
#define APP_VERSION "dev"
#endif

int main() {
    std::cout << "cpp-exe-test v" << APP_VERSION << "\n";
    std::cout << "2 + 3 = " << calc::add(2, 3) << "\n";
    std::cout << "10! = " << calc::factorial(10) << "\n";
    return 0;
}
