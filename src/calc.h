#pragma once

#include <cstdint>

namespace calc {

// Returns a + b.
std::int64_t add(std::int64_t a, std::int64_t b);

// Returns n! for 0 <= n <= 20. Throws std::out_of_range otherwise.
std::uint64_t factorial(int n);

}  // namespace calc
