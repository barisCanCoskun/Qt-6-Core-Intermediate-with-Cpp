# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "04QtConcurrent_autogen"
  "CMakeFiles/04QtConcurrent_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/04QtConcurrent_autogen.dir/ParseCache.txt"
  )
endif()
