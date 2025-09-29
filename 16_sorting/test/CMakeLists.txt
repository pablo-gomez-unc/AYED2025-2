add_executable(test_sorting test_sorting.cpp)
target_link_libraries(test_sorting gtest gtest_main)
target_include_directories(test_sorting PRIVATE ..)
