#include <type_traits>

#include <iterator>
static_assert(std::is_same_v<typename std::iterator_traits<int*>::value_type, int>);

#if __STDC_HOSTED__
    #include <iostream>
    std::istream_iterator<int> int_istream_iter{std::cin};
#endif

#include <utility>
void foo () {
    int i = 7;
    (void)std::move(i);
    (void)std::forward<int&>(i);
    std::integer_sequence<int, 8, 3, -6> seq{};
    (void)seq;
}

int main () {
    foo();
    return 0;
}
