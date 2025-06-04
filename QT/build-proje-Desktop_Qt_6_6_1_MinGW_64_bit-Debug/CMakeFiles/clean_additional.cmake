# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\proje_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\proje_autogen.dir\\ParseCache.txt"
  "proje_autogen"
  )
endif()
