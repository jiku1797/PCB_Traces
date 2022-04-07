# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "gui\\CMakeFiles\\PCB_Traces_GUI_autogen.dir\\AutogenUsed.txt"
  "gui\\CMakeFiles\\PCB_Traces_GUI_autogen.dir\\ParseCache.txt"
  "gui\\PCB_Traces_GUI_autogen"
  )
endif()
