# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\newwwww_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\newwwww_autogen.dir\\ParseCache.txt"
  "newwwww_autogen"
  )
endif()
