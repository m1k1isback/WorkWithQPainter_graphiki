# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\WorkWithQPainter_graphiki_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\WorkWithQPainter_graphiki_autogen.dir\\ParseCache.txt"
  "WorkWithQPainter_graphiki_autogen"
  )
endif()
