cmake_minimum_required (VERSION 3.5.0)
project (ldbnn)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# include our header files
include_directories(includes)
# add source
add_subdirectory (src)
# add examples
add_subdirectory (examples)
