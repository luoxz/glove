add_executable(tests_log MessageTest.cc)
target_link_libraries(tests_log vendor_gmock vendor_gtest_main glove)

add_dwarf_test(tests_log)
