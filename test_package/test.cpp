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

#include <numbers>
constexpr void numbers_test () {
    static_assert(std::numbers::pi - 3.14159 < 0.00001);
}

#include <optional>
constexpr void optional_test () {
    static_assert(std::optional<int>{}.value_or(7) == 7);
    static_assert(std::optional<int>{4}.value_or(7) == 4);
}

#include <ranges>
void ranges_test () {
    static constexpr std::array<double, 3> ar = {0.1, 2.3, 4.5};
    constexpr auto ar_plus_1 = ar |
        std::views::transform([] (double v) constexpr { return v + 1; });

    static_assert(ar_plus_1.size() == 3);
    static_assert(ar_plus_1[0] == 1.1);
    static_assert(ar_plus_1[1] == 3.3);
    static_assert(ar_plus_1[2] == 5.5);
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

#include <variant>
void variant_test () {
    struct Non_Trivial {
        Non_Trivial () {}
        Non_Trivial (double) {}
        Non_Trivial (Non_Trivial const&) {}
        Non_Trivial (Non_Trivial&&) {}
    };

    std::variant<Non_Trivial, int, double> var;

    struct Visitor {
        void operator () (Non_Trivial) {}
        void operator () (double) {}
        void operator () (int) {}
    };

    std::visit(Visitor{}, var);
}

int main () {
    iterator_test();
    optional_test();
    ranges_test();
    tuple_test();
    utility_test();
    variant_test();
    return 0;
}
