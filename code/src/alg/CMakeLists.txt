set(ALG_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/cpp/alg/algorithm.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/public/alg/algorithm.hpp"
)

add_library(alg STATIC ${ALG_FILES})

# add directory structure to IDEs
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/" FILES ${ALG_FILES})

target_include_directories(alg PUBLIC "include/public")
target_link_libraries(alg PUBLIC stf)