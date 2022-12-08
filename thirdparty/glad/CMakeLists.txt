
add_library("glad" STATIC "src/gl.c" "include/glad/gl.h" "include/KHR/khrplatform.h")

include_directories("include")
target_include_directories("glad" INTERFACE "include/")