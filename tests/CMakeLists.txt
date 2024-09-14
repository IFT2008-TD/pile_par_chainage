add_executable(
        test_pile
        test_pile.cpp
)

target_include_directories(test_pile PRIVATE ${PROJECT_SOURCE_DIR} )

target_link_libraries(
        test_pile
        gtest_main
        gtest
        pthread
)

include(GoogleTest)

gtest_discover_tests(test_pile)