#pragma once

#include <string>

#include "util/vector.h"

#include "window.h"

struct ImGuiStyle;

namespace vz
{

	class IApplication
	{
	public:
		IApplication(const std::string& title_, vz::Vec2i size_, vz::Vec2i pos_);
		virtual ~IApplication();

		void Start();

		virtual void Styling(ImGuiStyle* style_) {}

	private:

		void Update(float dt_);
		void Render();
		virtual void Draw() {}
		void Draw_Impl();

		void InitIMGUI();

	public:
		CommonWindow m_window;
	};
}
