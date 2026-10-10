#include "calc.h"

#include <stdexcept>

namespace calc {

std::int64_t add(std::int64_t a, std::int64_t b) {
    return a + b;
}

std::uint64_t factorial(int n) {
    if (n < 0 || n > 20) {
        throw std::out_of_range("factorial: n must be in [0, 20]");
    }
    std::uint64_t result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= static_cast<std::uint64_t>(i);
    }
    return result;
}

}  // namespace calc
