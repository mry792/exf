# exf

## Motivation

For embedded environments and others without an OS, a subset of the standard library is carved out and often made available as a [freestanding implementation](https://en.cppreference.com/w/cpp/freestanding) of the standard library. This excludes aspects of the standard library which might rely on features typically provided by an operating system including dynamic memory allocation, a filesystem, and an interactive terminal. However, as of C++20, there are many very useful aspects of the standard library unnecessarily excluded from the freestanding implementation. There are a number of ongoing efforts to improve this (ex: [P2268](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p2268r0.html) and [P0829](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p0829r4.html)) but `exf` is a library that can be used in the meantime to supplement the C++20 freestanding implementation.

## Introduction

`exf` is short for "Extended Freestanding." This library implements hosted parts of the standard library to supplement a freestanding implementation. It also includes a few extra features to supplement major parts of the standard library which cannot be be included in an embedded environment. (e.g. Instead of `std::vector`, this library provides `exf::static_vector` an implementation of the [static_vector](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0843r2.html) proposed for the standard library.)
