
set(VZ_APP_H
	"application.h"
)

set(VZ_APP_SRC
	"application.cpp"
)

add_library("ImGui" STATIC ${VZ_APP_H} ${VZ_APP_SRC})

