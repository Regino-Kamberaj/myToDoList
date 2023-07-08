add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp DateTest.cpp ToDoTest.cpp ToDoListTest.cpp ToDoListFixture.cpp)
add_executable(runToDoListTests ${SOURCE_TEST_FILES})
target_link_libraries(runToDoListTests gtest gtest_main core)