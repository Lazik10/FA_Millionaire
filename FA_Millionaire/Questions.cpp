// All the required questions for the game FA Millionaire with correct ansers
#include <ctime>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include "questions.h"
#include "FA_Millionaire.h"

namespace Questions
{
    const int MAX_QUESTIONS = 16;
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

    struct Question
    {
        std::string question;
        std::string answer_a;
        std::string answer_b;
        std::string answer_c;
        std::string asnwer_d;
        std::string question_correct_answer;
    };    

    Question questions[MAX_QUESTIONS]
    {
        // 1000
        {"Jaky produkt najdeme v FA Lab?", "PS100", "NOX", "Turba", "Aktuaotry", "PS100"},
        {"", "", "", "", ""},
        // 2000
        {"", "", "", "", ""},
        // 3000
        {"", "", "", "", ""},
        // 5000
        {"", "", "", "", ""},
        // 10 000 --- Save spot ---
        {"", "", "", "", ""},
        // 20 000
        {"", "", "", "", ""},
        // 40 000
        {"", "", "", "", ""},
        // 80 000
        {"", "", "", "", ""},
        // 160 000
        {"", "", "", "", ""},
        // 320 000 --- Save spot ---
        {"", "", "", "", ""},
        // 640 000
        {"", "", "", "", ""},
        // 1 250 000
        {"", "", "", "", ""},
        // 2 500 000
        {"", "", "", "", ""},
        // 5 000 000
        {"", "", "", "", ""},
        // 10 000 000
        {"", "", "", "", ""},
    };

    Questions::Questions()
    {
    }

    Questions::~Questions()
    {
    }

    void Questions::SelectQuestion()
    {
        std::string answerA;
        std::string answerB;
        std::string answerC;
        std::string answerD;

        int random_number = 0;
        srand(time(NULL));
        random_number = rand() % 1 /*MAX_QUESTIONS*/;

        std::vector<std::string> answers;
        // TO DO: Replace 0 with random number (this is only for test purpose)
        answers.push_back(questions[0].answer_a);
        answers.push_back(questions[0].answer_b);
        answers.push_back(questions[0].answer_c);
        answers.push_back(questions[0].asnwer_d);
        correct_answer = questions[0].question_correct_answer;

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

        if (answerA == questions->question_correct_answer)
            correct_answer_pos = ANSWER_A;
        else if (answerB == questions->question_correct_answer)
            correct_answer_pos = ANSWER_B;
        else if (answerC == questions->question_correct_answer)
            correct_answer_pos = ANSWER_C;
        else if (answerD == questions->question_correct_answer)
            correct_answer_pos = ANSWER_D;

        FAMillionaire::FA_Millionaire::question->Text = ConvertToSystemString(questions[0].question);
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

    void Questions::StartNewGame()
    {
        SelectQuestion();
    }

    bool Questions::EvaluateAnswer(System::String^ answer)
    {
        if (answer == ConvertToSystemString(correct_answer))
            return true;
        else
            return false;
    }

    void Questions::FiftyFifty()
    {
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
    }

    System::String^ Questions::GetAudienceHelp()
    {
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

        return audience_answer;
    }
};