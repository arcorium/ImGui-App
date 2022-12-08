#pragma once

#include <string>

#include <GLFW/glfw3.h>


#include "util/vector.h"

#include "window.h"

namespace vz
{

	class IApplication
	{
	public:
		IApplication(const std::string& title_, vz::Vec2i size_, vz::Vec2i pos_);
		virtual ~IApplication();

	private:
		
	};
}