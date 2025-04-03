enable_testing()

set(ALG_TEST_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/cpp/alg/algorithm_tests.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/private/alg/scaffolding/algorithm.hpp"
)

add_executable(tests ${ALG_TEST_FILES})

# add directory structure to IDEs
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/" FILES ${ALG_TEST_FILES})

target_include_directories(tests PRIVATE "include/private")

target_link_libraries(tests PRIVATE alg GTest::gtest_main)

# set up cpp files with precompiled headers
target_precompile_headers(tests PRIVATE <vector> <gtest/gtest.h> <stf/stf.hpp>)

include(GoogleTest)
gtest_discover_tests(tests)