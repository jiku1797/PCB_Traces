# CMakeList.txt : CMake project for PCB_Traces, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(THIS PCB_Traces)

set(Headers
	"PCB_Traces.h"
	"PrimitiveTraceTypes.h"
	"Trace.h"
	"TraceSet.h"
	"SegmentValidator.h" 
	"TraceController.h"
)

set(Sources
	"PCB_Traces.cpp"
	"Trace.cpp"
	"TraceSet.cpp"
	"SegmentValidator.cpp"
	"TraceController.cpp"
)

# Add source to this project's executable.
add_executable (${THIS}_run ${Sources} ${Headers})

# TODO: Add tests and install targets if needed.
enable_testing()

include(GoogleTest)

add_library(${THIS}_lib STATIC ${Sources})

