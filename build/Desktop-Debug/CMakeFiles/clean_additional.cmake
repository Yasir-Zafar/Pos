# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Pos_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Pos_autogen.dir/ParseCache.txt"
  "Pos_autogen"
  )
endif()
