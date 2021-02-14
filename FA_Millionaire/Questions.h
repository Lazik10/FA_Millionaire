#pragma once
#include <string>

namespace Questions
{

	class Questions
	{
	public:
		Questions();
		~Questions();

		static void StartNewGame();
		static void SelectQuestion();
		static bool EvaluateAnswer(bool end_game);
		static void FiftyFifty();
		static System::String^ GetAudienceHelp();
		static void GetPhoneHelp();
		static System::String^ ConvertToSystemString(std::string string);
		void SetCorrectAnswer(int position) { correct_answer_pos = position; };
		static void PlayCorrectBackgroundSound();
		static void FlashAnswerBackground(bool green, int flash_count);

	private:
		static int correct_answer_pos;
		static std::string correct_answer;
		static int fifty_fifty_erased_answers[2];
	};

};
