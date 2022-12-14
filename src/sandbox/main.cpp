#include <Windows.h>

#include "application.h"
#include "imgui.h"
#include "util/utility.h"

class Application : public vz::IApplication
{
public:
    using vz::IApplication::IApplication;

    void Styling(::ImGuiStyle* style_) override
    {

    }

protected:
    void Update(float dt_) override
    {
        SetShouldClose(!ms_isOpen);
    }

private:
    void Draw() override
    {
        ImGui::SetNextWindowSize({ 400.f, 600.f }, ImGuiCond_Always);
        ImGui::Begin(m_window.Title().c_str(), nullptr, 0);
        ImGui::End();

        ImGui::ShowDemoWindow(nullptr);
    }

private:
    inline static bool ms_isOpen = true;
};


DWORD WINAPI Main(LPVOID param_)
{
    Application app{ "mizhan", {400, 400}, {0, 0} };

    app.Start();

    FreeLibraryAndExitThread(GetModuleHandle(nullptr), 0);
}

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved)  // reserved
{
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, Main, nullptr, 0, nullptr));
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:

        if (lpvReserved != nullptr)
        {
            break; // do not do cleanup if process termination scenario
        }

        // Perform any necessary cleanup.
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}