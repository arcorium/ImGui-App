
#include "application.h"

namespace vz
{
	IApplication::IApplication(const std::string& title_, vz::Vec2i size_, vz::Vec2i pos_)
		: m_title{title_}, m_size{size_}, m_pos{pos_}
	{
	}

	IApplication::~IApplication()
	{
		glfwDestroyWindow(m_window);
	}
}
