# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Assignment11_autogen"
  "CMakeFiles/Assignment11_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Assignment11_autogen.dir/ParseCache.txt"
  )
endif()
