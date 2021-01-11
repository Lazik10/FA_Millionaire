#pragma once
//#include "QuestionSource.cpp"

struct Question
{
    std::string question;
    std::string answer_a;
    std::string answer_b;
    std::string answer_c;
    std::string asnwer_d;
    std::string question_correct_answer;
};

class QuestionSource
{
public:
	QuestionSource();
	~QuestionSource();
    static Question GetQuestion();

private:
};