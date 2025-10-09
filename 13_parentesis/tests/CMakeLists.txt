add_executable(parentesis_tests test_lista.cpp ../lista.hpp)
target_link_libraries(parentesis_tests PRIVATE gtest gtest_main)