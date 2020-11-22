// All the required questions for the game FA Millionaire with correct ansers
#include <ctime>
#include <vector>
#include <string>
#include <string.h>
#include "questions.h"
#include "FA_Millionaire.h"

namespace Questions
{
    const int MAX_QUESTIONS = 16;

    struct Question
    {
        std::string question;
        std::string answer_a;
        std::string answer_b;
        std::string answer_c;
        std::string asnwer_d;
        std::string correct_answer;
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

        unsigned int random_number = 0;
        srand(time(NULL));
        random_number = rand() % 1 /*MAX_QUESTIONS*/;

        std::vector<std::string> answers;
        // TO DO: Replace 0 with random number (this is only for test purpose)
        answers.push_back(questions[0].answer_a);
        answers.push_back(questions[0].answer_b);
        answers.push_back(questions[0].answer_c);
        answers.push_back(questions[0].asnwer_d);

        for (int i = 0; i < 4; i++)
        {
            int random_answer_number = rand() % answers.size();
            switch (i)
            {
            case 0:
                answerA = "A: " + answers[random_answer_number];
                break;
            case 1:
                answerB = "B: " + answers[random_answer_number];
                break;
            case 2:
                answerC = "C: " + answers[random_answer_number];
                break;
            case 3:
                answerD = "D: " + answers[random_answer_number];
                break;
            default:
                break;
            }

            answers.erase(answers.begin() + random_answer_number);
        }

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

    void Questions::StartGame()
    {
        SelectQuestion();
    }
};