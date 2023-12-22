# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "02WritingFiles_autogen"
  "CMakeFiles/02WritingFiles_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/02WritingFiles_autogen.dir/ParseCache.txt"
  )
endif()
