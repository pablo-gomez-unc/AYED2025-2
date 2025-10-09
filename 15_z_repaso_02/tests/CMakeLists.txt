add_executable(15_z_repaso02_tests test_carrito.cpp  ../carrito.hpp ../producto.hpp)
target_link_libraries(15_z_repaso02_tests PRIVATE gtest gtest_main)