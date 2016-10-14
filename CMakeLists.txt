cmake_minimum_required (VERSION 3.5.0)
project (ldbnn)

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
include_directories(includes)
add_subdirectory (src)
add_subdirectory (examples)
