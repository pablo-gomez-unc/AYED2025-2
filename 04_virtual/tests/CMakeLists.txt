add_executable(04_virtual_tests test_virtual.cpp ../Forma.cpp ../Circulo.cpp)
target_link_libraries(04_virtual_tests PRIVATE gtest gtest_main)

