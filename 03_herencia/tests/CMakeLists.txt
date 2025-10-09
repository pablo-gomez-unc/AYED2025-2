add_executable(03_herencia_tests test_herencia.cpp ../Persona.cpp ../Estudiante.cpp)
target_link_libraries(03_herencia_tests PRIVATE gtest gtest_main)
