#include <utility>

int main () {
    int i = 7;
    (void)std::move(i);
    (void)std::forward<int&>(i);
    std::integer_sequence<int, 8, 3, -6> seq{};
    (void)seq;

    return 0;
}
