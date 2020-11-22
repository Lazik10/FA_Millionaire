#pragma once
#include <string>

namespace Questions
{

	class Questions
	{
	public:
		Questions();
		~Questions();

		static void StartGame();
		static void SelectQuestion();
		static System::String^ ConvertToSystemString(std::string string);

	private:

	};

};
