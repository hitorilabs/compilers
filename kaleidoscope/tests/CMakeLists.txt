include(GoogleTest)

file(GLOB TEST_SOURCES "test_*.cpp")

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(
        ${TEST_NAME}
        # smolcc
        GTest::gtest_main
        )
    gtest_discover_tests(${TEST_NAME})
endforeach()

