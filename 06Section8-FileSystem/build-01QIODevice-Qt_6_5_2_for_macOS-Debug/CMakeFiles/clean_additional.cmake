# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "01QIODevice_autogen"
  "CMakeFiles/01QIODevice_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/01QIODevice_autogen.dir/ParseCache.txt"
  )
endif()
