# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "06TypeDef_autogen"
  "CMakeFiles/06TypeDef_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/06TypeDef_autogen.dir/ParseCache.txt"
  )
endif()
