#pragma once
#include "FA_Millionaire.h"
#include "wtypes.h"
#include "WinUser.h"
#include "windows.h"
#include <chrono>
#include <ctime>
#include <iomanip>

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

std::vector<std::wstring> prize_money = { L"1,000", L"2,000", L"3,000", L"5,000", L"10,000",
                                        L"20,000", L"40,000", L"80,000", L"160,000", L"320,000",
                                        L"640,000", L"1,280,000", L"2,500,000", L"5,000,000", L"10,000,000" };

std::vector<std::wstring> round_name = { L"1", L"2", L"3", L"4",
                                        L"5", L"6", L"7", L"8", L"9",
                                        L"10", L"11", L"12", L"13", L"14", L"15" };

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
    final_score->Visible = false;

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

std::vector<std::wstring> FAMillionaire::FA_Millionaire::GetStandingsInput()
{
    // Read the standings file and save the data to vector
    std::wifstream standings_stream(L"standings.txt");
    std::locale loc("cs_CZ.UTF-8");
    standings_stream.imbue(loc);
    std::vector<std::wstring> temp;
    std::wstring line;

    if (standings_stream.is_open() && standings_stream.peek() != std::ifstream::traits_type::eof())
    {
        while (getline(standings_stream, line))
        {
            temp.push_back(line);
        }
        standings_stream.close();
    }

    return temp;
}

PlayerData FAMillionaire::FA_Millionaire::GetPlayerData()
{
    // Player Data
    PlayerData player;

    player.round = round_name[round];

    String^ player_nickname = player_name_label->Text;
    // Reduce first 8 letters because of Player: prefix 
    player_nickname = player_nickname->Substring(8);
    pin_ptr<const wchar_t> w_player_nickname = PtrToStringChars(player_nickname);
    player.nickname = w_player_nickname;

    std::time_t t = std::time(nullptr);
    std::tm timestamp = *std::localtime(&t);
    static const wchar_t* format = L"%d/%m/%y";
    std::wostringstream time;
    time << std::put_time(&timestamp, format);
    player.date = time.str();

    // Final prize should be from the previous round if player decides to leave
    // the game without answering question or if he quess the wrong answer
    player.money = prize_money[round];

    return player;
}

void FAMillionaire::FA_Millionaire::ModifyStandings(bool first_launch)
{
    std::wfstream myfile;
    std::locale loc("cs_CZ.UTF-8");

    if (first_launch)
    {
        // Create new standings
        myfile.open("standings.txt", std::ios::app, std::ios::binary);
        myfile.imbue(loc);
        myfile.close();
    }
    else
    {
        // Create empty standings vector
        std::vector<PlayerData> standings;
        std::vector<std::wstring> temp;

        PlayerData player = GetPlayerData();
        temp = GetStandingsInput();

        PlayerData standings_player;
        std::wstring standings_data;

        if (!temp.empty())
        {
            // Parse all lines as a new player data
            for (std::vector<std::wstring>::iterator temp_itr = temp.begin(); temp_itr != temp.end(); ++temp_itr)
            {
                int while_count = 0;
                std::wistringstream sentence(*temp_itr);

                while (sentence >> standings_data)
                {
                    switch (while_count)
                    {
                    case 0:
                        standings_player.round = standings_data;
                        break;
                    case 1:
                        standings_player.nickname = standings_data;
                        break;
                    case 2:
                        standings_player.date = standings_data;
                        break;
                    case 3:
                        standings_player.money = standings_data;
                        break;
                    default:
                        break;
                    }
                    while_count++;
                }
                standings.push_back(standings_player);
            }
        }

        int position_in_standings = 0;

        if (!standings.empty())
        {
            for (std::vector<PlayerData>::iterator itr = standings.begin(); itr != standings.end(); ++itr)
            {
                int standings_round_resoult = 0;

                for (std::vector<std::wstring>::iterator itr2 = prize_money.begin(); itr2 != prize_money.end(); ++itr2)
                {
                    if (*itr2 == (*itr).money)
                        break;
                    standings_round_resoult++;
                }

                // If we find player in standings with lower round result then we have a position at which 
                // we can insert our new player and also remove last player from standings
                if (standings_round_resoult <= round)
                {
                    standings.insert(standings.begin() + position_in_standings, player);
                    break;
                }

                position_in_standings++;
            }

            // Only store 10 best players in Standings
            while (standings.size() > 10)
            {
                standings.pop_back();
            }
        }

        // Now we just need to copy the new standings into the standings.txt file
        std::wstring output;
        if (!standings.empty())
        {
            for (std::vector<PlayerData>::iterator itr = standings.begin(); itr != standings.end(); ++itr)
            {
                output += (*itr).round + L" " + (*itr).nickname + L" " + (*itr).date + L" " + (*itr).money + L"\n";
            }
        }
        else
        {
            output += player.round + L" " + player.nickname + L" " + player.date + L" " + player.money + L"\n";
        }
        myfile.open("standings.txt");
        myfile << output;
        myfile.close();
    }
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

void FAMillionaire::FA_Millionaire::ModifyFinalScoreLabel()
{
    PlayerData player = GetPlayerData();
    String^ player_nickname = gcnew String(player.nickname.c_str());
    String^ player_prize_money = gcnew String(player.money.c_str());
    final_score->Text = L"Congratulations " + player_nickname + L", you have just won " + player_prize_money + L"!";
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
