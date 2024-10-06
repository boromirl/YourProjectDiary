# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\YourProjectDiary_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\YourProjectDiary_autogen.dir\\ParseCache.txt"
  "YourProjectDiary_autogen"
  )
endif()
