

set(VZ_IMGUI_H
	"imconfig.h"
	"imgui.h"
	"imgui_internal.h"
	"imstb_rectpack.h"
	"imstb_textedit.h"
	"imstb_truetype.h"

#	"backends/imgui_impl_android.h"
	"backends/imgui_impl_dx10.h"
	"backends/imgui_impl_dx11.h"
	"backends/imgui_impl_dx12.h"
	"backends/imgui_impl_dx9.h"
	"backends/imgui_impl_glfw.h"
	"backends/imgui_impl_opengl2.h"
	"backends/imgui_impl_opengl3.h"
	"backends/imgui_impl_opengl3_loader.h"
	"backends/imgui_impl_win32.h"
)

set(VZ_IMGUI_SRC
	"imgui.cpp"
	"imgui_demo.cpp"
	"imgui_draw.cpp"
	"imgui_tables.cpp"
	"imgui_widgets.cpp"

#	"backends/imgui_impl_android.cpp"
	"backends/imgui_impl_dx10.cpp"
	"backends/imgui_impl_dx11.cpp"
	"backends/imgui_impl_dx12.cpp"
	"backends/imgui_impl_dx9.cpp"
	"backends/imgui_impl_glfw.cpp"
	"backends/imgui_impl_opengl2.cpp"
	"backends/imgui_impl_opengl3.cpp"
	"backends/imgui_impl_win32.cpp"
)

include_directories(.)

add_library("ImGui" ${VZ_IMGUI_H} ${VZ_IMGUI_SRC})

target_link_libraries("ImGui" PUBLIC glfw)

target_include_directories("ImGui" INTERFACE .)