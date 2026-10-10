#include <iostream>
#include <stdexcept>

#include "calc.h"

namespace {

int g_failures = 0;

void check(bool condition, const char* expr, int line) {
    if (!condition) {
        ++g_failures;
        std::cerr << "FAIL (line " << line << "): " << expr << "\n";
    }
}

#define CHECK(expr) check((expr), #expr, __LINE__)

template <typename Fn>
bool throws_out_of_range(Fn fn) {
    try {
        fn();
    } catch (const std::out_of_range&) {
        return true;
    }
    return false;
}

}  // namespace

int main() {
    CHECK(calc::add(2, 3) == 5);
    CHECK(calc::add(-4, 4) == 0);
    CHECK(calc::add(-7, -8) == -15);

    CHECK(calc::factorial(0) == 1u);
    CHECK(calc::factorial(1) == 1u);
    CHECK(calc::factorial(5) == 120u);
    CHECK(calc::factorial(10) == 3628800u);
    CHECK(calc::factorial(20) == 2432902008176640000ull);
    CHECK(throws_out_of_range([] { calc::factorial(-1); }));
    CHECK(throws_out_of_range([] { calc::factorial(21); }));

    if (g_failures != 0) {
        std::cerr << g_failures << " check(s) failed\n";
        return 1;
    }
    std::cout << "All tests passed\n";
    return 0;
}
