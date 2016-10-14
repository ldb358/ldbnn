add_library (L_NN nn.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (L_NN PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
