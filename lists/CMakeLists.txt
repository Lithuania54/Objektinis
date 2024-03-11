set(SOURCE_FILES Funkcijoslists.cpp Lists.cpp)
add_executable(lists ${SOURCE_FILES})
target_include_directories(lists PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
