
set(headers_path "${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_CXX_COMPILER_ID}/${CMAKE_CXX_COMPILER_VERSION}")
if (NOT EXISTS "${headers_path}")
    message(FATAL_ERROR "${CMAKE_CXX_COMPILER_ID} compiler v${CMAKE_CXX_COMPILER_VERSION} is not supported.")
endif ()

include(GNUInstallDirs)

###
# library definition
###

add_library(std INTERFACE)
file(
    GLOB_RECURSE
    source_files
    RELATIVE .
    CONFIGURE_DEPENDS
    "${headers_path}/*"
)
target_sources(std INTERFACE ${source_files})
target_include_directories(
    std
    INTERFACE
        $<BUILD_INTERFACE:${headers_path}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

###
# install library
###

# For when consumed as a subdirectory.
add_library(${PROJECT_NAME}::std ALIAS std)

install(
    DIRECTORY ${headers_path}/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
