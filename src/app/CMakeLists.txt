
set(VZ_APP_H
	"application.h"
 "window.h")

set(VZ_APP_SRC
	"application.cpp"
 "window.cpp")

add_library("Application" STATIC ${VZ_APP_H} ${VZ_APP_SRC})

target_link_libraries("Application" PRIVATE ImGui glfw freetype)

