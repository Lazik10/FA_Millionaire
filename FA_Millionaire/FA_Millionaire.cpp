#include "FA_Millionaire.h"
#include "wtypes.h"
#include "WinUser.h"
#include "windows.h"
#pragma comment(lib, "user32.lib")

using namespace System;
using namespace System::Windows::Forms;

const int FIRST_SAVE_ROUND = 4;
const int SECOND_SAVE_ROUND = 9;

struct RoundPrizeBackground
{
    int round;
    std::string background_name;
};

const int MAX_ROUND = 15;
RoundPrizeBackground round_prize_background[MAX_ROUND]
{
    { 0, "FA_Millionaire_0002s_0014_1000" },
    { 1, "FA_Millionaire_0002s_0013_2000"},
    { 2, "FA_Millionaire_0002s_0012_3000"},
    { 3, "FA_Millionaire_0002s_0011_5000"},
    { 4, "FA_Millionaire_0002s_0010_10000"},
    { 5, "FA_Millionaire_0002s_0009_20000"},
    { 6, "FA_Millionaire_0002s_0008_40000"},
    { 7, "FA_Millionaire_0002s_0007_80000"},
    { 8, "FA_Millionaire_0002s_0006_160000"},
    { 9, "FA_Millionaire_0002s_0005_320000"},
    { 10, "FA_Millionaire_0002s_0004_640000"},
    { 11, "FA_Millionaire_0002s_0003_1250000"},
    { 12, "FA_Millionaire_0002s_0002_2500000"},
    { 13, "FA_Millionaire_0002s_0001_5000000"},
    { 14, "FA_Millionaire_0002s_0000_10000000"},
};

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

void FAMillionaire::FA_Millionaire::SetDefaultState(bool new_game)
{
    if (new_game)
    {
        round = 0;
        audience_used = false;
        audience->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(L"audience.BackgroundImage")));
        phone_used = false;
        phone->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(L"phone.BackgroundImage")));
        fifty_fifty_used = false;
        fifty_fifty->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(L"fifty_fifty.BackgroundImage")));
        picturePrizeChart->Image = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(L"picturePrizeChart.Image")));
        game_in_progress = true;

        PlaySound(MAKEINTRESOURCE(IDR_WAVE5), GetModuleHandle(NULL), SND_RESOURCE | SND_LOOP | SND_ASYNC);
    }

    audience_resoults->Visible = false;

    answer_A->BackColor = System::Drawing::Color::Transparent;
    answer_B->BackColor = System::Drawing::Color::Transparent;
    answer_C->BackColor = System::Drawing::Color::Transparent;
    answer_D->BackColor = System::Drawing::Color::Transparent;

    answer_A->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
    answer_B->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
    answer_C->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
    answer_D->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;

    SetStatusAnswerSelected(false);
    SetEvaluateTimer(2000);
}

void FAMillionaire::FA_Millionaire::SetCorrectQuestionPrizeBackground(bool game_over)
{
    if (!game_over)
    {
        if (GetRound() < MAX_ROUND)
        {
            String^ picture_name = Questions::Questions::ConvertToSystemString(round_prize_background[GetRound()].background_name);
            picturePrizeChart->Image = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(picture_name)));
        }
    }
    else
    {
        int save_spot_image = 0;
        if (round >= FIRST_SAVE_ROUND && round < SECOND_SAVE_ROUND)
            save_spot_image = FIRST_SAVE_ROUND;
        else if (round >= SECOND_SAVE_ROUND)
            save_spot_image = SECOND_SAVE_ROUND;

        String^ picture_name = Questions::Questions::ConvertToSystemString(round_prize_background[save_spot_image].background_name);
        picturePrizeChart->Image = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(picture_name)));
    }
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
