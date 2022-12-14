#pragma once

#include <string>

#include "util/vector.h"

#include "window.h"

struct ImGuiStyle;
struct ImGuiIO;

namespace vz
{

	class IApplication
	{
	public:
		IApplication(const std::string& title_, vz::Vec2i size_, vz::Vec2i pos_);
		virtual ~IApplication();

		void Start();

		virtual void Styling(ImGuiStyle* style_) {}
		virtual void SettingIO(ImGuiIO& io_) {};

		void SetShouldClose(bool condition_);

	protected:
		virtual void Update(float dt_) {}

	private:

		void Render();
		virtual void Draw() {}
		void Update_Impl(float dt_);
		void Draw_Impl();

		void InitIMGUI();

	public:
		CommonWindow m_window;
	};
}
