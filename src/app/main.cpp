
//#include "window.h"
#include "application.h"

#include <iostream>

#include "imgui.h"

class Application : public vz::IApplication
{
public:
	using vz::IApplication::IApplication;

	void Styling(::ImGuiStyle* style_) override
	{

	}

private:
	void Draw() override
	{
		static bool isOpened = false;
		ImGui::SetNextWindowSize({ (float)m_window.Size().x, (float)m_window.Size().y });
		ImGui::SetNextWindowPos({ (float)m_window.Position().x, (float)m_window.Position().y });
		ImGui::Begin(m_window.Title().c_str(), &isOpened, ImGuiWindowFlags_NoCollapse);

		ImGui::End();

		ImGui::Begin("asd", &isOpened);

		ImGui::End();
	}
};


int main()
{

	Application app{ "mizhan", {400, 400}, {0, 0} };

	app.Start();
	std::cout << "Hellaw" << std::endl;
}