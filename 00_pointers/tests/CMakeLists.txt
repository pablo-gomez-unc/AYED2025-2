add_executable(00_pointers_tests main_test.cpp ../funciones.cpp ../funciones.hpp)
target_link_libraries(00_pointers_tests PRIVATE gtest gtest_main)