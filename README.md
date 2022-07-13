# Extended Freestanding

## Motivation

For embedded environments and others without an OS, a subset of the C++ standard library is carved out and often made available as a [freestanding implementation](https://en.cppreference.com/w/cpp/freestanding) of the standard library. This excludes aspects of the standard library which might rely on features typically provided by an operating system including dynamic memory allocation, a filesystem, and an interactive terminal. However, as of C++20, there are many very useful aspects of the standard library unnecessarily excluded from the freestanding implementation. There are a number of ongoing efforts to improve this (ex: [P2268](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p2268r0.html) and [P0829](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p0829r4.html)) but `exf` is a library that can be used in the meantime to supplement the C++20 freestanding implementation.

## Implemented Headers

| header | What is supported? |
| --- | --- |
| [\<array\>](https://en.cppreference.com/w/cpp/header/array) | Everything except `array::at` functions. |
| [\<iterator\>](https://en.cppreference.com/w/cpp/header/iterator) | Everything except stream and streambuf iterators. |
| [\<optional\>](https://en.cppreference.com/w/cpp/header/optional) | Everything except `optional::value` functions. |
| [\<tuple\>](https://en.cppreference.com/w/cpp/header/tuple) | Fully supported. (Though allocators have not been tested with tuples.) |
| [\<utility\>](https://en.cppreference.com/w/cpp/header/utility) | Fully supported. |

## Supported Compilers

Right now the only supported compmiler is GNU and only version `11.2.0`. I have plans to support more versions of GNU in the future but my focus right now is on including more parts of the standard library.
