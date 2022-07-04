#! /usr/bin/env python3

from conan import ConanFile
from conan.tools import build
from conan.tools.cmake import CMake


class ExfTestRecipe (ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    test_type = 'explicit'
    generators = 'CMakeToolchain', 'cmake_paths'

    def requirements (self):
        self.requires(self.tested_reference_str)

    def build (self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test (self):
        if not build.cross_building(self):
            self.run('./test')
