# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "04SerializingToXML_autogen"
  "CMakeFiles/04SerializingToXML_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/04SerializingToXML_autogen.dir/ParseCache.txt"
  )
endif()
