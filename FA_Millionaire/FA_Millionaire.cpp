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

int FAMillionaire::FA_Millionaire::GetRound()
{
    return round;
}

void FAMillionaire::FA_Millionaire::SetRound(int question_round)
{
    round = question_round;
}

int FAMillionaire::FA_Millionaire::GetTimer()
{
    return FA_Millionaire::run_time;
}

void FAMillionaire::FA_Millionaire::SetTimer(int diff)
{
    run_time += diff;
}

void FAMillionaire::FA_Millionaire::SetDefaultState()
{
    round = 0;
    audience_used = false;
    audience->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(L"audience.BackgroundImage")));
    phone_used = false;
    phone->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(L"phone.BackgroundImage")));
    fifty_fifty_used = false;
    fifty_fifty->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(L"fifty_fifty.BackgroundImage")));
    audience_resoults->Visible = false;

    answer_A->BackColor = System::Drawing::Color::Transparent;
    answer_B->BackColor = System::Drawing::Color::Transparent;
    answer_C->BackColor = System::Drawing::Color::Transparent;
    answer_D->BackColor = System::Drawing::Color::Transparent;

    answer_A->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
    answer_B->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
    answer_C->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
    answer_D->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
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
