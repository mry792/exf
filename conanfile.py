#! /usr/bin/env python3

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.scm import Git


class ExfRecipe (ConanFile):
    name = 'extended-freestanding'
    version = '0.0.1'

    license = 'GNU GENERAL PUBLIC LICENSE'
    author = 'M. Emery Goss <m.goss792@gmail.com>'
    url = 'https://github.com/mry792/exf.git'
    description = (
        'Implementations of parts of the hosted standard library to be used '
        'in freestanding environments.'
    )

    settings = 'compiler', 'build_type'
    generators = 'CMakeToolchain'

    def source (self):
        git = Git(self)
        git.clone(self.url)

    def layout (self):
        cmake_layout(self)

    def build (self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package (self):
        cmake = CMake(self)
        cmake.install()

    def package_id (self):
        del self.info.settings.build_type
