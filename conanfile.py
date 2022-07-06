#! /usr/bin/env python3

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.files import update_conandata
from conan.tools.scm import Git
from conans.tools import Git as LegacyGit


class ExfRecipe (ConanFile):
    name = 'extended-freestanding'
    # version = (computed from local repo)

    license = 'GNU GENERAL PUBLIC LICENSE'
    author = 'M. Emery Goss <m.goss792@gmail.com>'
    url = 'https://github.com/mry792/exf.git'
    description = (
        'Implementations of parts of the hosted standard library to be used '
        'in freestanding environments.'
    )

    settings = 'compiler', 'build_type'
    generators = 'CMakeToolchain'

    def set_version (self):
        git = LegacyGit(self.recipe_folder)
        tag = git.run('describe --tags')
        self.version = tag[1:]

    def export (self):
        git = Git(self, self.recipe_folder)
        scm_url, scm_commit = git.get_url_and_commit()
        update_conandata(self, {
            'source': {
                'commit': scm_commit,
                'url': scm_url
            }
        })

    def source (self):
        git = Git(self)
        source = self.conan_data['source']
        git.clone(source['url'], target = '.')
        git.checkout(source['commit'])

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
