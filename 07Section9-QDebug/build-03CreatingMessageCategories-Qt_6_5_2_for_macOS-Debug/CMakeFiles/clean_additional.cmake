# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "03CreatingMessageCategories_autogen"
  "CMakeFiles/03CreatingMessageCategories_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/03CreatingMessageCategories_autogen.dir/ParseCache.txt"
  )
endif()
