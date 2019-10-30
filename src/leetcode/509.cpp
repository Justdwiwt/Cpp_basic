#include <array>
#include <cstddef>

template<size_t N>
struct Fibonacci : std::integral_constant<size_t, Fibonacci<N - 1>::value + Fibonacci<N - 2>::value> {
};

template<>
struct Fibonacci<0> : std::integral_constant<size_t, 0> {
};

template<>
struct Fibonacci<1> : std::integral_constant<size_t, 1> {
};

template<size_t ...Is>
static constexpr std::array<size_t, sizeof...(Is)> make_fib_seq(std::index_sequence<Is...>) {
    return {Fibonacci<Is>::value...};
}

static constexpr auto fibSeq = make_fib_seq(std::make_index_sequence<31>());

class Solution {
public:
    int fib(int N) {
        return fibSeq[N];
    }
};
