
set(VZ_APP_H
	"application.h"
 "window.h" "key.h")

set(VZ_APP_SRC
	"application.cpp"
 "window.cpp")

add_library("Application" STATIC ${VZ_APP_H} ${VZ_APP_SRC})
#add_executable("Application" ${VZ_APP_H} ${VZ_APP_SRC})

target_link_libraries("Application" PUBLIC ImGui freetype glad)

target_include_directories("Application" INTERFACE .)