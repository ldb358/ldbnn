cmake_minimum_required (VERSION 3.5.0)
project (ldbnn)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# includeour header files
include_directories(includes)
# add source
add_subdirectory (src)
# add examples
add_subdirectory (examples)

file(GLOB test_SRC
	"tests/*.cpp"
)
add_executable(catch_tests ${test_SRC})
target_link_libraries(catch_tests L_NN)
add_test(runall catch_tests)

add_custom_target(run
	COMMAND catch_tests
	DEPENDS catch_tests
	WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)


