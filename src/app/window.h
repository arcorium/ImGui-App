#pragma once

#include <string>

#include "util/vector.h"

#include <GLFW/glfw3.h>

namespace vz
{
	class IWindow
	{
	public:
		virtual ~IWindow() = default;

		virtual vz::Vec2i Size() const = 0;
		virtual vz::Vec2i Position() const = 0;

		virtual void Move(vz::Vec2i pos_) = 0;
	};

	class ICommonWindow : public IWindow
	{
	public:
		ICommonWindow(const std::string& title_, const vz::Vec2i size_, const vz::Vec2i pos_);

	private:
		GLFWwindow* m_window;

		std::string m_title;
		vz::Vec2i m_size;
		vz::Vec2i m_position;
	};
}