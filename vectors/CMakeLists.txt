set(SOURCE_FILES Funkcijosvector.cpp Vektoriai.cpp)
add_executable(vektoriai ${SOURCE_FILES})
target_include_directories(vektoriai PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
