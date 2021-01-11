#pragma once
// All the required questions for the game FA Millionaire with correct ansers
#include <ctime>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include "questions.h"
#include "FA_Millionaire.h"
#include "QuestionSource.h"

namespace Questions
{
    const int MAX_ROUNDS = 15;
    int Questions::correct_answer_pos = 0;
    std::string Questions::correct_answer = "";
    int Questions::fifty_fifty_erased_answers[2] = { 0, 0 };

    enum Answer
    {
        ANSWER_A,
        ANSWER_B,
        ANSWER_C,
        ANSWER_D,
        WRONG,
        CORRECT,
    };

    Questions::Questions()
    {
    }

    Questions::~Questions()
    {
    }

    void Questions::SelectQuestion()
    {
        if (FAMillionaire::FA_Millionaire::GetRound() >= MAX_ROUNDS)
            return;

        PlayCorrectBackgroundSound();

        std::string answerA;
        std::string answerB;
        std::string answerC;
        std::string answerD;

        Question selected_question;
        selected_question = QuestionSource::GetQuestion();

        std::vector<std::string> answers;
        answers.push_back(selected_question.answer_a);
        answers.push_back(selected_question.answer_b);
        answers.push_back(selected_question.answer_c);
        answers.push_back(selected_question.asnwer_d);
        correct_answer = selected_question.question_correct_answer;

        for (int i = 0; i < 4; i++)
        {
            int random_answer_number = rand() % answers.size();
            switch (i)
            {
            case ANSWER_A:
                answerA = answers[random_answer_number];
                break;
            case ANSWER_B:
                answerB = answers[random_answer_number];
                break;
            case ANSWER_C:
                answerC = answers[random_answer_number];
                break;
            case ANSWER_D:
                answerD = answers[random_answer_number];
                break;
            default:
                break;
            }

            answers.erase(answers.begin() + random_answer_number);
        }

        if (answerA == correct_answer)
            correct_answer_pos = ANSWER_A;
        else if (answerB == correct_answer)
            correct_answer_pos = ANSWER_B;
        else if (answerC == correct_answer)
            correct_answer_pos = ANSWER_C;
        else if (answerD == correct_answer)
            correct_answer_pos = ANSWER_D;

        FAMillionaire::FA_Millionaire::question->Text = ConvertToSystemString(selected_question.question);
        FAMillionaire::FA_Millionaire::answer_A->Text = ConvertToSystemString(answerA);
        FAMillionaire::FA_Millionaire::answer_B->Text = ConvertToSystemString(answerB);
        FAMillionaire::FA_Millionaire::answer_C->Text = ConvertToSystemString(answerC);
        FAMillionaire::FA_Millionaire::answer_D->Text = ConvertToSystemString(answerD);
    }

    System::String^ Questions::ConvertToSystemString(std::string string)
    {
        std::string str = string;
        System::String^ newSystemString = gcnew System::String(str.c_str());
        return newSystemString;
    }

    void Questions::PlayCorrectBackgroundSound()
    {
        if (FAMillionaire::FA_Millionaire::GetRound() < 5)
            PlaySound(MAKEINTRESOURCE(IDR_WAVE5), GetModuleHandle(NULL), SND_RESOURCE | SND_LOOP | SND_ASYNC);
        else if (FAMillionaire::FA_Millionaire::GetRound() < 10)
            PlaySound(MAKEINTRESOURCE(IDR_WAVE6), GetModuleHandle(NULL), SND_RESOURCE | SND_LOOP |SND_ASYNC);
        else
            PlaySound(MAKEINTRESOURCE(IDR_WAVE7), GetModuleHandle(NULL), SND_RESOURCE | SND_LOOP | SND_ASYNC);
    }

    void Questions::FlashAnswerBackground(bool green, int flash_count)
    {
        if ((flash_count % 2) == 0)
        {

            switch (correct_answer_pos)
            {
            case 0:
                FAMillionaire::FA_Millionaire::answer_A->BackColor = System::Drawing::Color::Green;
                FAMillionaire::FA_Millionaire::answer_A->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Green;
                break;
            case 1:
                FAMillionaire::FA_Millionaire::answer_B->BackColor = System::Drawing::Color::Green;
                FAMillionaire::FA_Millionaire::answer_B->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Green;
                break;
            case 2:
                FAMillionaire::FA_Millionaire::answer_C->BackColor = System::Drawing::Color::Green;
                FAMillionaire::FA_Millionaire::answer_C->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Green;
                break;
            case 3:
                FAMillionaire::FA_Millionaire::answer_D->BackColor = System::Drawing::Color::Green;
                FAMillionaire::FA_Millionaire::answer_D->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Green;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (correct_answer_pos)
            {
            case 0:
                FAMillionaire::FA_Millionaire::answer_A->BackColor = System::Drawing::Color::Black;
                FAMillionaire::FA_Millionaire::answer_A->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
                break;
            case 1:
                FAMillionaire::FA_Millionaire::answer_B->BackColor = System::Drawing::Color::Black;
                FAMillionaire::FA_Millionaire::answer_B->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
                break;
            case 2:
                FAMillionaire::FA_Millionaire::answer_C->BackColor = System::Drawing::Color::Black;
                FAMillionaire::FA_Millionaire::answer_C->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
                break;
            case 3:
                FAMillionaire::FA_Millionaire::answer_D->BackColor = System::Drawing::Color::Black;
                FAMillionaire::FA_Millionaire::answer_D->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
                break;
            default:
                break;
            }
        }
    }

    void Questions::StartNewGame()
    {
        SelectQuestion();
        FAMillionaire::FA_Millionaire::SetStatusAnswerSelected(false);
    }

    bool Questions::EvaluateAnswer()
    {
        int round = FAMillionaire::FA_Millionaire::GetRound();

        if (round >= MAX_ROUNDS)
            return false;

        // If Correct answer prepare next round and flash the correct answer button
        if (FAMillionaire::FA_Millionaire::GetSelectedAnswerPos() == correct_answer_pos)
        {
            round++;
            FAMillionaire::FA_Millionaire::SetRound(round);
            FAMillionaire::FA_Millionaire::SetNextQuestionTimer(5000);

            FAMillionaire::FA_Millionaire::SetFlashingButton(true);

            if (FAMillionaire::FA_Millionaire::GetRound() < 5)
                PlaySound(MAKEINTRESOURCE(IDR_WAVE9), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
            else if (FAMillionaire::FA_Millionaire::GetRound() < 10)
                PlaySound(MAKEINTRESOURCE(IDR_WAVE11), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
            else if (FAMillionaire::FA_Millionaire::GetRound() < 15)
                PlaySound(MAKEINTRESOURCE(IDR_WAVE13), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
            else
                PlaySound(MAKEINTRESOURCE(IDR_WAVE8), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
            return true;
        }
        else
        {
            FAMillionaire::FA_Millionaire::SetGameStatus(false);

            if (FAMillionaire::FA_Millionaire::GetRound() < 5)
                PlaySound(MAKEINTRESOURCE(IDR_WAVE10), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
            else if (FAMillionaire::FA_Millionaire::GetRound() < 10)
                PlaySound(MAKEINTRESOURCE(IDR_WAVE12), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
            else
                PlaySound(MAKEINTRESOURCE(IDR_WAVE14), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
        }

        // If Wrong answer show the correct one
        if (FAMillionaire::FA_Millionaire::answer_A->Text == ConvertToSystemString(correct_answer))
        {
            FAMillionaire::FA_Millionaire::answer_A->BackColor = System::Drawing::Color::Green;
            FAMillionaire::FA_Millionaire::answer_A->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Green;
            FAMillionaire::FA_Millionaire::answer_A->BackgroundImage = nullptr;
        }
        else if (FAMillionaire::FA_Millionaire::answer_B->Text == ConvertToSystemString(correct_answer))
        {
            FAMillionaire::FA_Millionaire::answer_B->BackColor = System::Drawing::Color::Green;
            FAMillionaire::FA_Millionaire::answer_B->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Green;
            FAMillionaire::FA_Millionaire::answer_B->BackgroundImage = nullptr;
        }
        else if (FAMillionaire::FA_Millionaire::answer_C->Text == ConvertToSystemString(correct_answer))
        {
            FAMillionaire::FA_Millionaire::answer_C->BackColor = System::Drawing::Color::Green;
            FAMillionaire::FA_Millionaire::answer_C->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Green;
            FAMillionaire::FA_Millionaire::answer_C->BackgroundImage = nullptr;
        }
        else if (FAMillionaire::FA_Millionaire::answer_D->Text == ConvertToSystemString(correct_answer))
        {
            FAMillionaire::FA_Millionaire::answer_D->BackColor = System::Drawing::Color::Green;
            FAMillionaire::FA_Millionaire::answer_D->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Green;
            FAMillionaire::FA_Millionaire::answer_D->BackgroundImage = nullptr;
        }

        if (FAMillionaire::FA_Millionaire::GetSelectedAnswerPos() == correct_answer_pos)
            return true;
        else
            return false;
    }

    void Questions::FiftyFifty()
    {
        PlaySound(MAKEINTRESOURCE(IDR_WAVE19), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);

        std::vector<int> answers;

        if (FAMillionaire::FA_Millionaire::answer_A->Text != ConvertToSystemString(correct_answer))
            answers.push_back(ANSWER_A);
        if (FAMillionaire::FA_Millionaire::answer_B->Text != ConvertToSystemString(correct_answer))
            answers.push_back(ANSWER_B);
        if (FAMillionaire::FA_Millionaire::answer_C->Text != ConvertToSystemString(correct_answer))
            answers.push_back(ANSWER_C);
        if (FAMillionaire::FA_Millionaire::answer_D->Text != ConvertToSystemString(correct_answer))
            answers.push_back(ANSWER_D);

        int rand_pos = (rand() % answers.size());

        answers.erase(answers.begin() + rand_pos);
        int vector_pos = 0;
        
        for (auto itr = answers.begin(); itr != answers.end(); itr++)
        {
            fifty_fifty_erased_answers[vector_pos] = answers[vector_pos];
            switch (answers[vector_pos])
            {
            case 0:
                FAMillionaire::FA_Millionaire::answer_A->Text = "";
                break;
            case 1:
                FAMillionaire::FA_Millionaire::answer_B->Text = "";
                break;
            case 2:
                FAMillionaire::FA_Millionaire::answer_C->Text = "";
                break;
            case 3:
                FAMillionaire::FA_Millionaire::answer_D->Text = "";
                break;
            default:
                break;
            };

            vector_pos++;
        }

        FAMillionaire::FA_Millionaire::SetBackgroundMusic(true);
    }

    System::String^ Questions::GetAudienceHelp()
    {
        PlaySound(MAKEINTRESOURCE(IDR_WAVE19), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);

        System::String^ audience_answer = "";
        unsigned short int audience_help = correct_answer_pos;

        // Remove correct answer
        std::vector<unsigned short int> wrong_answer_options{ ANSWER_A, ANSWER_B, ANSWER_C, ANSWER_D };
        wrong_answer_options.erase(wrong_answer_options.begin() + correct_answer_pos);
        unsigned int wrong_answer_options_size = wrong_answer_options.size();

        if (FAMillionaire::FA_Millionaire::GetFiftyFiftyStatus())
        {
            for (unsigned int i = 0; i < wrong_answer_options_size; i++ )
            {
                if (wrong_answer_options[i] == fifty_fifty_erased_answers[0] ||
                    wrong_answer_options[i] == fifty_fifty_erased_answers[1])
                {
                    wrong_answer_options.erase(wrong_answer_options.begin() + i);
                    wrong_answer_options_size--;
                }
            }
        }

        if (FAMillionaire::FA_Millionaire::GetRound() > 4 && FAMillionaire::FA_Millionaire::GetRound() < 10)
        {
            // 5% to make the audiance be wrong
            if ((rand() % 100) < 5)
            {
                audience_help = wrong_answer_options[(rand() % wrong_answer_options.size())];
            }
        }
        else if (FAMillionaire::FA_Millionaire::GetRound() >= 10)
        {
            // 30% to make the audiance be wrong
            if ((rand() % 100) < 30)
            {
                audience_help = wrong_answer_options[(rand() % wrong_answer_options.size())];
            }
        }

        switch (audience_help)
        {
        case ANSWER_A:
            audience_answer = "FA_Millionaire_0000s_0000_Audience A";
            break;
        case ANSWER_B:
            audience_answer = "FA_Millionaire_0000s_0001_Audience B";
            break;
        case ANSWER_C:
            audience_answer = "FA_Millionaire_0000s_0002_Audience C";
            break;
        case ANSWER_D:
            audience_answer = "FA_Millionaire_0000s_0003_Audience D";
            break;
        default:
            break;
        }

        FAMillionaire::FA_Millionaire::SetBackgroundMusic(true);

        return audience_answer;
    }

    void Questions::GetPhoneHelp()
    {
        unsigned short int phone_help = correct_answer_pos;

        // Remove correct answer
        std::vector<unsigned short int> wrong_answer_options{ ANSWER_A, ANSWER_B, ANSWER_C, ANSWER_D };
        wrong_answer_options.erase(wrong_answer_options.begin() + correct_answer_pos);
        unsigned int wrong_answer_options_size = wrong_answer_options.size();

        if (FAMillionaire::FA_Millionaire::GetFiftyFiftyStatus())
        {
            for (unsigned int i = 0; i < wrong_answer_options_size; i++)
            {
                if (wrong_answer_options[i] == fifty_fifty_erased_answers[0] ||
                    wrong_answer_options[i] == fifty_fifty_erased_answers[1])
                {
                    wrong_answer_options.erase(wrong_answer_options.begin() + i);
                    wrong_answer_options_size--;
                }
            }
        }

        if (FAMillionaire::FA_Millionaire::GetRound() > 4 && FAMillionaire::FA_Millionaire::GetRound() < 10)
        {
            // 5% to make the audiance be wrong
            if ((rand() % 100) < 5)
            {
                phone_help = wrong_answer_options[(rand() % wrong_answer_options.size())];
            }
        }
        else if (FAMillionaire::FA_Millionaire::GetRound() >= 10)
        {
            // 30% to make the audiance be wrong
            if ((rand() % 100) < 30)
            {
                phone_help = wrong_answer_options[(rand() % wrong_answer_options.size())];
            }
        }

        switch (phone_help)
        {
        case ANSWER_A:
            PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_SYNC);
            break;
        case ANSWER_B:
            PlaySound(MAKEINTRESOURCE(IDR_WAVE2), GetModuleHandle(NULL), SND_RESOURCE | SND_SYNC);
            break;
        case ANSWER_C:
            PlaySound(MAKEINTRESOURCE(IDR_WAVE3), GetModuleHandle(NULL), SND_RESOURCE | SND_SYNC);
            break;
        case ANSWER_D:
            PlaySound(MAKEINTRESOURCE(IDR_WAVE4), GetModuleHandle(NULL), SND_RESOURCE | SND_SYNC);
            break;
        default:
            break;
        }

        PlayCorrectBackgroundSound();
    }
};