# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "02Intervals_autogen"
  "CMakeFiles/02Intervals_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/02Intervals_autogen.dir/ParseCache.txt"
  )
endif()
