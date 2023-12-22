# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "03WorkingWithAProcess_autogen"
  "CMakeFiles/03WorkingWithAProcess_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/03WorkingWithAProcess_autogen.dir/ParseCache.txt"
  )
endif()
