# CMakeList.txt : Test project CMake file

cmake_minimum_required (VERSION 3.10)

set(TESTS ${CMAKE_PROJECT_NAME}_tst)

set(Test_Headers
	"Trace_test.h"
	"TraceSet_test.h"
	"SegmentValidator_test.h"
	"TraceController_test.h"
)

set(Test_Sources
	"tests.cpp"
	"TraceSet_test.cpp"
	"Trace_test.cpp"
	"SegmentValidator_test.cpp"
	"TraceController_test.cpp"
)

set(SOURCES ${Test_Sources})

add_executable(${TESTS} ${Test_Sources} ${Test_Headers})

add_test(NAME ${TESTS} COMMAND ${TESTS})

target_link_libraries(${TESTS} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest_main)