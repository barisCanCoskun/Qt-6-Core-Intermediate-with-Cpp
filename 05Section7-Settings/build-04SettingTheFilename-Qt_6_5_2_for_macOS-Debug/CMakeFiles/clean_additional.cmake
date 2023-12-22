# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "04SettingTheFilename_autogen"
  "CMakeFiles/04SettingTheFilename_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/04SettingTheFilename_autogen.dir/ParseCache.txt"
  )
endif()
