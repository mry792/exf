#include <type_traits>

#include <array>
static_assert(std::is_same_v<typename std::array<double, 7>::iterator, double*>);
#if __STDC_HOSTED__
    static_assert(std::is_same_v<decltype(std::declval<std::array<int, 4>>().at(2)), int&>);
#endif

#include <iterator>
#if __STDC_HOSTED__
    #include <iostream>
#endif
void iterator_test () {
    static_assert(std::is_same_v<typename std::iterator_traits<int*>::value_type, int>);

    #if __STDC_HOSTED__
        std::ostream_iterator<int> int_ostream_iter{std::cout};
    #endif
}

#include <tuple>
void tuple_test () {
    std::tuple<int, double> tup{7, 3.2};
    (void)tup;
}

#include <utility>
void utility_test () {
    int i = 7;
    (void)std::move(i);
    (void)std::forward<int&>(i);
    std::integer_sequence<int, 8, 3, -6> seq{};
    (void)seq;
}

int main () {
    iterator_test();
    tuple_test();
    utility_test();
    return 0;
}
