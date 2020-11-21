#include "FA_Millionaire.h"
#include "wtypes.h"
#include "WinUser.h"
#include "windows.h"
#pragma comment(lib, "user32.lib")

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    FAMillionaire::FA_Millionaire form;
    Application::Run(% form);
}

int FAMillionaire::FA_Millionaire::GetTimer()
{
    return FA_Millionaire::run_time;
}

void FAMillionaire::FA_Millionaire::SetTimer(int diff)
{
    run_time += diff;
}

//void GetDesktopResolution(int& horizontal, int& vertical)
int FAMillionaire::FA_Millionaire::GetDesktopResolution(bool horizontal)
{
    RECT desktop;
    // Get a handle to the desktop window
    const HWND hDesktop = GetDesktopWindow();
    // Get the size of screen to the variable desktop
    GetWindowRect(hDesktop, &desktop);
    // The top left corner will have coordinates (0,0)
    // and the bottom right corner will have coordinates
    // (horizontal, vertical)
    if (horizontal)
        return desktop.right;
    else 
        return desktop.bottom;
}