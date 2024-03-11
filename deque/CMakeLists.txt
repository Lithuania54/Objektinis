set(SOURCE_FILES Funkcijosdeque.cpp Deque.cpp)
add_executable(deque ${SOURCE_FILES})
target_include_directories(deque PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
