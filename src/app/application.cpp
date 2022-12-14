
#include "application.h"

#include <chrono>

#include <glad/gl.h>
#include "imgui.h"
#include "imgui_internal.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"

namespace vz
{
	IApplication::IApplication(const std::string& title_, vz::Vec2i size_, vz::Vec2i pos_)
		: m_window{title_, size_, pos_}
	{
	}

	IApplication::~IApplication()
	{
		ImGui_ImplGlfw_Shutdown();
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();
	}

	void IApplication::Start()
	{
		// Lazy init
		InitIMGUI();

		auto last = std::chrono::high_resolution_clock::now();
		auto present = std::chrono::high_resolution_clock::now();

		while(!m_window.IsClosed())
		{
			// get delta time from present and last frame
			// currently relying on chrono std
			present = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float, std::ratio<1, 1>> delta = present - last;
			last = present;

			Update_Impl(delta.count());
			Draw_Impl();
			Render();
		}
	}

	void IApplication::SetShouldClose(bool condition_)
	{
		m_window.SetShouldClose(condition_);
	}

	void IApplication::Render()
	{
		ImGui::Render();
		vz::Vec2i framebufferSize;
		glfwGetFramebufferSize(m_window.Native(), &framebufferSize.x, &framebufferSize.y);

		glViewport(0, 0, framebufferSize.x, framebufferSize.y);
		glClearColor(0.f, 0.f, 0.f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* lastCurrentContext = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(lastCurrentContext);
		}

		m_window.Render();	// in glfw swap buffer
	}

	void IApplication::Update_Impl(float dt_)
	{
		m_window.Update(dt_);
		Update(dt_);
	}

	void IApplication::Draw_Impl()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		Draw();
	}

	void IApplication::InitIMGUI()
	{
		IMGUI_CHECKVERSION();

		const auto context = ImGui::CreateContext();

		auto& io = context->IO;
		// Set default config
		//io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;	// enable
		//io.ConfigWindowsMoveFromTitleBarOnly = true;
		//io.ConfigWindowsResizeFromEdges = true;
		//io.IniFilename = nullptr;

		SettingIO(io);

		ImGui_ImplGlfw_InitForOpenGL(m_window.Native(), true);
		ImGui_ImplOpenGL3_Init("#version 130");

		ImGui::StyleColorsLight();

		Styling(&ImGui::GetStyle());
	}
}
