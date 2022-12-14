#include "window.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "Key.h"

#include "util/enum.hpp"

namespace vz
{
	CommonWindow::CommonWindow(const std::string& title_, const vz::Vec2i size_, const vz::Vec2i pos_)
		: m_title{title_}, m_size{size_}, m_position{pos_}
	{
		InitGLFW();
		InitGLAD();
	}

	CommonWindow::~CommonWindow()
	{
		glfwDestroyWindow(m_nativeWindow);
		glfwTerminate();
	}

	void CommonWindow::Move(const vz::Vec2i& pos_)
	{
		glfwSetWindowPos(m_nativeWindow, pos_.x, pos_.y);
	}

	void CommonWindow::SetSize(const vz::Vec2i& size_)
	{
		glfwSetWindowSize(m_nativeWindow, size_.x, size_.y);
	}

	vz::Vec2i CommonWindow::Size() const
	{
		glfwGetWindowSize(m_nativeWindow, &m_size.x, &m_size.y);

		return m_size;
	}

	vz::Vec2i CommonWindow::Position() const
	{
		glfwGetWindowPos(m_nativeWindow, &m_position.x, &m_position.y);

		return m_position;
	}

	std::string CommonWindow::Title() const
	{
		return m_title;
	}

	GLFWwindow* CommonWindow::Native() const
	{
		return m_nativeWindow;
	}

	bool CommonWindow::IsClosed() const
	{
		return glfwWindowShouldClose(m_nativeWindow);
	}

	void CommonWindow::SetShouldClose(bool condition_)
	{
		glfwSetWindowShouldClose(m_nativeWindow, condition_);
	}

	void CommonWindow::OnMouseMove(vz::Vec2d pos_)
	{
		
	}

	void CommonWindow::OnKey(Key key_, int scancode_, State action_, Modifier mods_)
	{
	}

	void CommonWindow::Render_Impl()
	{
		glfwSwapBuffers(m_nativeWindow);
	}

	void CommonWindow::HandleInput()
	{
		glfwPollEvents();
	}

	void CommonWindow::InitGLFW()
	{
		// GLFW Initialization
		VASSERT(glfwInit(), "Failed to init glfw");

		// Window Properties Settings
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_SAMPLES, 16);
		glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
		glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
		glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
		//glfwWindowHint(GLFW_DECORATED, false);
		//glfwWindowHint(GLFW_VISIBLE, false);

		// Window Creation
		m_nativeWindow = glfwCreateWindow(m_size.x, m_size.y, m_title.c_str(), nullptr, nullptr);
		VASSERT(m_nativeWindow, "Failed to create window");

		glfwMakeContextCurrent(m_nativeWindow);
		glfwSwapInterval(1);

		glfwSetWindowUserPointer(m_nativeWindow, this);
		glfwSetCursorPosCallback(m_nativeWindow, [](GLFWwindow* window, double xpos, double ypos)
			{
				auto ctx = static_cast<CommonWindow*>(glfwGetWindowUserPointer(window));
				ctx->OnMouseMove(vz::Vec2d{ xpos, ypos });
			});
		glfwSetKeyCallback(m_nativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				auto ctx = static_cast<CommonWindow*>(glfwGetWindowUserPointer(window));
				ctx->OnKey(static_cast<Key>(key), scancode, static_cast<State>(action), static_cast<Modifier>(mods));
			});
	}

	void CommonWindow::InitGLAD()
	{
		VASSERT(gladLoadGL(glfwGetProcAddress), "Failed to init glad");
	}
}
