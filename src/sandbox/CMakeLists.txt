

set(VZ_SANDBOX_H
)

set(VZ_SANDBOX_SRC
	"main.cpp"
)

add_library("Sandbox" SHARED ${VZ_SANDBOX_H} ${VZ_SANDBOX_SRC})

target_link_libraries("Sandbox" PRIVATE Application)