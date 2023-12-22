# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "02QVector_autogen"
  "CMakeFiles/02QVector_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/02QVector_autogen.dir/ParseCache.txt"
  )
endif()
