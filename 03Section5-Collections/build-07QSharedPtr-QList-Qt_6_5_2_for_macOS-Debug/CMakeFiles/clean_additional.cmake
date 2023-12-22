# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "07QSharedPtr-QList_autogen"
  "CMakeFiles/07QSharedPtr-QList_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/07QSharedPtr-QList_autogen.dir/ParseCache.txt"
  )
endif()
