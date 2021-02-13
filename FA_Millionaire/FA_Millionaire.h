#pragma once
#include "Questions.h"
#include <Windows.h>
#include <mmsystem.h>
#include "resource.h"
#include <vector>
#include <fstream>
#include <locale>
#include <vcclr.h>
#include <sstream>
#include <cliext/vector>

struct PlayerData
{
	std::wstring round;
	std::wstring nickname;
	std::wstring date;
	std::wstring money;
};

namespace FAMillionaire {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int INTRO_TIME = 18000;

	/// <summary>
	/// Summary for FA_Millionaire
	/// </summary>
	public ref class FA_Millionaire : public System::Windows::Forms::Form
	{
	public:
		FA_Millionaire(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	System::ComponentModel::ComponentResourceManager^ resources_fa_millionaire;
	public: static System::Windows::Forms::Button^ answer_A;
	public: static System::Windows::Forms::Button^ answer_B;
	public: static System::Windows::Forms::Button^ answer_C;
	public: static System::Windows::Forms::Button^ answer_D;
	public: static System::Windows::Forms::Label^ question;
	public: static System::Windows::Forms::Label^ player_name_label;

	private: System::Windows::Forms::Button^ fifty_fifty;
	private: System::Windows::Forms::Button^ phone;
	private: System::Windows::Forms::Button^ audience;
	private: System::Windows::Forms::PictureBox^ vitesco_logo;
	private: System::Windows::Forms::PictureBox^ fa_edition_logo;
	private: System::Windows::Forms::Button^ new_game;
	private: System::Windows::Forms::Button^ exit;
	private: System::Windows::Forms::PictureBox^ audience_resoults;
	private: System::Windows::Forms::Button^ standings;
	private: System::Windows::Forms::Button^ login;
	private: System::Windows::Forms::TextBox^ name_box;
	private: System::Windows::Forms::PictureBox^ standings_background;
	private: System::Windows::Forms::Label^ first_position_label;
	private: System::Windows::Forms::Label^ second_position_label;
	private: System::Windows::Forms::Label^ third_position_label;
	private: System::Windows::Forms::Label^ fourth_position_label;
	private: System::Windows::Forms::Label^ fifth_position_label;
	private: System::Windows::Forms::Label^ sixth_position_label;
	private: System::Windows::Forms::Label^ seventh_position_label;
	private: System::Windows::Forms::Label^ eight_position_label;
	private: System::Windows::Forms::Label^ ninth_position_label;
	private: System::Windows::Forms::Label^ tenth_position_label;
	private: System::Windows::Forms::Label^ standings_legend;
	private: System::Windows::Forms::Label^ final_score;
	private: System::Windows::Forms::PictureBox^ logo_millionaire;

	public:

		static int GetRound();
		static void SetRound(int round);
		static int GetTimer();
		static void SetTimer(int diff);
		static void SetEvaluateTimer(int timer) { evaluate_timer = timer; };
		static void SetNextQuestionTimer(int timer) { next_question_timer = timer; };
		static void SetNextQuestion(bool status) { next_question = status; };
		static bool GetFiftyFiftyStatus() { return fifty_fifty_used; };
		static bool GetStatusAnswerSelected() { return answer_selected; };
		static void SetStatusAnswerSelected(bool status) { answer_selected = status; };
		static int GetSelectedAnswerPos() { return selected_answer_pos; };
		static void SetGameStatus(bool game_runing) { game_in_progress = game_runing; };
		static void SetFlashingButton(bool flash) { answer_flashing = flash; };
		static void SetBackgroundMusic(bool enabled) { background_music = enabled; };
		static void ModifyStandings(bool first_launch);
		static FAMillionaire::FA_Millionaire::PlayerData GetPlayerData();
		static std::vector<std::wstring> GetStandingsInput();
		void ModifyFinalScoreLabel();
		void SetCorrectQuestionPrizeBackground(bool game_over);
		void SetDefaultState(bool new_game);
		int GetDesktopResolution(bool horizontal);
		//void GetDesktopResolution(int& vertical, int& horizontal);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FA_Millionaire()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ picturePrizeChart;
	private: System::Windows::Forms::PictureBox^ background;
	private: System::Windows::Forms::PictureBox^ question_template;
	private: System::Windows::Forms::Timer^ timer;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		static int run_time = 0;
		static int round = 0;
		static int next_question_timer = 0;
		static int evaluate_timer = 0;
		static int selected_answer_pos = 0;
		static int flashing_timer = 1000;
		static int background_music_timer = 2000;
		static int flash_count = 0;
		static bool fifty_fifty_used = false;
		static bool audience_used = false;
		static bool phone_used = false;
		static bool answer_selected = false;
		static bool next_question = false;
		static bool game_in_progress = false;
		static bool answer_flashing = false;
		static bool background_music = false;
		static bool evaluate = false;
		static bool login_success = false;
		static bool standings_shown = false;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FA_Millionaire::typeid));
			resources_fa_millionaire = resources;
			this->picturePrizeChart = (gcnew System::Windows::Forms::PictureBox());
			this->background = (gcnew System::Windows::Forms::PictureBox());
			this->question_template = (gcnew System::Windows::Forms::PictureBox());
			this->question = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->answer_A = (gcnew System::Windows::Forms::Button());
			this->answer_B = (gcnew System::Windows::Forms::Button());
			this->answer_C = (gcnew System::Windows::Forms::Button());
			this->answer_D = (gcnew System::Windows::Forms::Button());
			this->fifty_fifty = (gcnew System::Windows::Forms::Button());
			this->phone = (gcnew System::Windows::Forms::Button());
			this->audience = (gcnew System::Windows::Forms::Button());
			this->vitesco_logo = (gcnew System::Windows::Forms::PictureBox());
			this->fa_edition_logo = (gcnew System::Windows::Forms::PictureBox());
			this->new_game = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->audience_resoults = (gcnew System::Windows::Forms::PictureBox());
			this->standings = (gcnew System::Windows::Forms::Button());
			this->login = (gcnew System::Windows::Forms::Button());
			this->name_box = (gcnew System::Windows::Forms::TextBox());
			this->player_name_label = (gcnew System::Windows::Forms::Label());
			this->logo_millionaire = (gcnew System::Windows::Forms::PictureBox());
			this->first_position_label = (gcnew System::Windows::Forms::Label());
			this->second_position_label = (gcnew System::Windows::Forms::Label());
			this->third_position_label = (gcnew System::Windows::Forms::Label());
			this->fourth_position_label = (gcnew System::Windows::Forms::Label());
			this->fifth_position_label = (gcnew System::Windows::Forms::Label());
			this->sixth_position_label = (gcnew System::Windows::Forms::Label());
			this->seventh_position_label = (gcnew System::Windows::Forms::Label());
			this->eight_position_label = (gcnew System::Windows::Forms::Label());
			this->ninth_position_label = (gcnew System::Windows::Forms::Label());
			this->tenth_position_label = (gcnew System::Windows::Forms::Label());
			this->standings_legend = (gcnew System::Windows::Forms::Label());
			this->standings_background = (gcnew System::Windows::Forms::PictureBox());
			this->final_score = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturePrizeChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->background))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->question_template))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vitesco_logo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fa_edition_logo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->audience_resoults))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo_millionaire))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->standings_background))->BeginInit();
			this->SuspendLayout();
			// 
			// picturePrizeChart
			// 
			this->picturePrizeChart->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picturePrizeChart->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picturePrizeChart.Image")));
			this->picturePrizeChart->Location = System::Drawing::Point(1226, 0);
			this->picturePrizeChart->Name = L"picturePrizeChart";
			this->picturePrizeChart->Size = System::Drawing::Size(694, 1080);
			this->picturePrizeChart->TabIndex = 1;
			this->picturePrizeChart->TabStop = false;
			// 
			// background
			// 
			this->background->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->background->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"background.Image")));
			this->background->Location = System::Drawing::Point(-1, 35);
			this->background->Name = L"background";
			this->background->Size = System::Drawing::Size(1234, 617);
			this->background->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->background->TabIndex = 2;
			this->background->TabStop = false;
			// 
			// question_template
			// 
			this->question_template->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"question_template.Image")));
			this->question_template->Location = System::Drawing::Point(-1, 642);
			this->question_template->Name = L"question_template";
			this->question_template->Size = System::Drawing::Size(1234, 372);
			this->question_template->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->question_template->TabIndex = 3;
			this->question_template->TabStop = false;
			// 
			// question
			// 
			this->question->AutoEllipsis = true;
			this->question->BackColor = System::Drawing::Color::Transparent;
			this->question->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->question->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->question->ForeColor = System::Drawing::Color::Silver;
			this->question->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"question.Image")));
			this->question->Location = System::Drawing::Point(93, 686);
			this->question->Name = L"question";
			this->question->Size = System::Drawing::Size(1024, 108);
			this->question->TabIndex = 4;
			this->question->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &FA_Millionaire::timer_Tick);
			// 
			// answer_A
			// 
			this->answer_A->BackColor = System::Drawing::Color::Transparent;
			this->answer_A->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"answer_A.BackgroundImage")));
			this->answer_A->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->answer_A->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->answer_A->FlatAppearance->BorderSize = 0;
			this->answer_A->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->answer_A->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->answer_A->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->answer_A->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_A->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_A->ForeColor = System::Drawing::Color::Silver;
			this->answer_A->Location = System::Drawing::Point(141, 854);
			this->answer_A->Name = L"answer_A";
			this->answer_A->Size = System::Drawing::Size(356, 53);
			this->answer_A->TabIndex = 5;
			this->answer_A->Text = L" ";
			this->answer_A->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_A->UseVisualStyleBackColor = false;
			this->answer_A->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_A_Click);
			// 
			// answer_B
			// 
			this->answer_B->BackColor = System::Drawing::Color::Transparent;
			this->answer_B->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"answer_B.BackgroundImage")));
			this->answer_B->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->answer_B->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->answer_B->FlatAppearance->BorderSize = 0;
			this->answer_B->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->answer_B->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->answer_B->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->answer_B->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_B->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_B->ForeColor = System::Drawing::Color::Silver;
			this->answer_B->Location = System::Drawing::Point(784, 854);
			this->answer_B->Name = L"answer_B";
			this->answer_B->Size = System::Drawing::Size(356, 53);
			this->answer_B->TabIndex = 5;
			this->answer_B->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_B->UseVisualStyleBackColor = true;
			this->answer_B->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_B_Click);
			// 
			// answer_C
			// 
			this->answer_C->BackColor = System::Drawing::Color::Transparent;
			this->answer_C->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"answer_C.BackgroundImage")));
			this->answer_C->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->answer_C->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->answer_C->FlatAppearance->BorderSize = 0;
			this->answer_C->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->answer_C->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->answer_C->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->answer_C->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_C->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_C->ForeColor = System::Drawing::Color::Silver;
			this->answer_C->Location = System::Drawing::Point(141, 938);
			this->answer_C->Name = L"answer_C";
			this->answer_C->Size = System::Drawing::Size(356, 53);
			this->answer_C->TabIndex = 5;
			this->answer_C->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_C->UseVisualStyleBackColor = true;
			this->answer_C->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_C_Click);
			// 
			// answer_D
			// 
			this->answer_D->BackColor = System::Drawing::Color::Transparent;
			this->answer_D->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"answer_D.BackgroundImage")));
			this->answer_D->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->answer_D->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->answer_D->FlatAppearance->BorderSize = 0;
			this->answer_D->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->answer_D->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->answer_D->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->answer_D->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_D->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_D->ForeColor = System::Drawing::Color::Silver;
			this->answer_D->Location = System::Drawing::Point(784, 939);
			this->answer_D->Name = L"answer_D";
			this->answer_D->Size = System::Drawing::Size(355, 53);
			this->answer_D->TabIndex = 5;
			this->answer_D->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_D->UseVisualStyleBackColor = true;
			this->answer_D->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_D_Click);
			// 
			// fifty_fifty
			// 
			this->fifty_fifty->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fifty_fifty.BackgroundImage")));
			this->fifty_fifty->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->fifty_fifty->Location = System::Drawing::Point(1311, 83);
			this->fifty_fifty->Name = L"fifty_fifty";
			this->fifty_fifty->Size = System::Drawing::Size(155, 135);
			this->fifty_fifty->TabIndex = 6;
			this->fifty_fifty->UseVisualStyleBackColor = true;
			this->fifty_fifty->Click += gcnew System::EventHandler(this, &FA_Millionaire::fifty_fifty_Click);
			// 
			// phone
			// 
			this->phone->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"phone.BackgroundImage")));
			this->phone->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->phone->Location = System::Drawing::Point(1472, 83);
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(155, 135);
			this->phone->TabIndex = 6;
			this->phone->UseVisualStyleBackColor = false;
			this->phone->Click += gcnew System::EventHandler(this, &FA_Millionaire::phone_Click);
			// 
			// audience
			// 
			this->audience->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"audience.BackgroundImage")));
			this->audience->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->audience->Location = System::Drawing::Point(1633, 83);
			this->audience->Name = L"audience";
			this->audience->Size = System::Drawing::Size(155, 135);
			this->audience->TabIndex = 6;
			this->audience->UseVisualStyleBackColor = false;
			this->audience->Click += gcnew System::EventHandler(this, &FA_Millionaire::audience_Click);
			// 
			// vitesco_logo
			// 
			this->vitesco_logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"vitesco_logo.Image")));
			this->vitesco_logo->Location = System::Drawing::Point(0, 0);
			this->vitesco_logo->Margin = System::Windows::Forms::Padding(0);
			this->vitesco_logo->Name = L"vitesco_logo";
			this->vitesco_logo->Size = System::Drawing::Size(1924, 80);
			this->vitesco_logo->TabIndex = 7;
			this->vitesco_logo->TabStop = false;
			// 
			// fa_edition_logo
			// 
			this->fa_edition_logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fa_edition_logo.Image")));
			this->fa_edition_logo->Location = System::Drawing::Point(-1, 1006);
			this->fa_edition_logo->Name = L"fa_edition_logo";
			this->fa_edition_logo->Size = System::Drawing::Size(1924, 71);
			this->fa_edition_logo->TabIndex = 8;
			this->fa_edition_logo->TabStop = false;
			// 
			// new_game
			// 
			this->new_game->BackColor = System::Drawing::Color::Yellow;
			this->new_game->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->new_game->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->new_game->Location = System::Drawing::Point(29, 13);
			this->new_game->Name = L"new_game";
			this->new_game->Size = System::Drawing::Size(275, 52);
			this->new_game->TabIndex = 9;
			this->new_game->Text = L"New Game";
			this->new_game->UseVisualStyleBackColor = false;
			this->new_game->Click += gcnew System::EventHandler(this, &FA_Millionaire::new_game_Click);
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::Yellow;
			this->exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit->Location = System::Drawing::Point(1619, 1016);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(275, 52);
			this->exit->TabIndex = 10;
			this->exit->Text = L"Exit Game";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &FA_Millionaire::exit_Click);
			// 
			// audience_resoults
			// 
			this->audience_resoults->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"audience_resoults.Image")));
			this->audience_resoults->Location = System::Drawing::Point(954, 118);
			this->audience_resoults->Name = L"audience_resoults";
			this->audience_resoults->Size = System::Drawing::Size(255, 332);
			this->audience_resoults->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->audience_resoults->TabIndex = 11;
			this->audience_resoults->TabStop = false;
			this->audience_resoults->Visible = false;
			// 
			// standings
			// 
			this->standings->BackColor = System::Drawing::Color::Yellow;
			this->standings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->standings->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->standings->Location = System::Drawing::Point(405, 13);
			this->standings->Name = L"standings";
			this->standings->Size = System::Drawing::Size(275, 52);
			this->standings->TabIndex = 9;
			this->standings->Text = L"Standings";
			this->standings->UseVisualStyleBackColor = false;
			this->standings->Click += gcnew System::EventHandler(this, &FA_Millionaire::standings_Click);
			// 
			// login
			// 
			this->login->BackColor = System::Drawing::Color::Yellow;
			this->login->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->login->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login->Location = System::Drawing::Point(1619, 13);
			this->login->Name = L"login";
			this->login->Size = System::Drawing::Size(275, 52);
			this->login->TabIndex = 9;
			this->login->Text = L"Login";
			this->login->UseVisualStyleBackColor = false;
			this->login->Click += gcnew System::EventHandler(this, &FA_Millionaire::login_Click);
			// 
			// name_box
			// 
			this->name_box->BackColor = System::Drawing::Color::White;
			this->name_box->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->name_box->Font = (gcnew System::Drawing::Font(L"Cooper Black", 33, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name_box->Location = System::Drawing::Point(1214, 13);
			this->name_box->Margin = System::Windows::Forms::Padding(10);
			this->name_box->Name = L"name_box";
			this->name_box->Size = System::Drawing::Size(356, 51);
			this->name_box->TabIndex = 12;
			this->name_box->Text = L"...Insert Name...";
			this->name_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->name_box->Click += gcnew System::EventHandler(this, &FA_Millionaire::name_box_Click);
			// 
			// player_name_label
			// 
			this->player_name_label->BackColor = System::Drawing::Color::Yellow;
			this->player_name_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player_name_label->Location = System::Drawing::Point(1229, 18);
			this->player_name_label->Name = L"player_name_label";
			this->player_name_label->Size = System::Drawing::Size(275, 52);
			this->player_name_label->TabIndex = 13;
			this->player_name_label->Text = L"Player Name";
			this->player_name_label->Visible = false;
			// 
			// logo_millionaire
			// 
			this->logo_millionaire->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo_millionaire.Image")));
			this->logo_millionaire->Location = System::Drawing::Point(0, 0);
			this->logo_millionaire->Name = L"logo_millionaire";
			this->logo_millionaire->Size = System::Drawing::Size(1920, 1080);
			this->logo_millionaire->TabIndex = 15;
			this->logo_millionaire->TabStop = false;
			// 
			// first_position_label
			// 
			this->first_position_label->BackColor = System::Drawing::Color::Yellow;
			this->first_position_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->first_position_label->Location = System::Drawing::Point(445, 164);
			this->first_position_label->Name = L"first_position_label";
			this->first_position_label->Size = System::Drawing::Size(695, 45);
			this->first_position_label->TabIndex = 17;
			this->first_position_label->Text = L"0 - Player - Date - 0 CZK";
			this->first_position_label->Visible = false;
			// 
			// second_position_label
			// 
			this->second_position_label->BackColor = System::Drawing::Color::Yellow;
			this->second_position_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->second_position_label->Location = System::Drawing::Point(445, 209);
			this->second_position_label->Name = L"second_position_label";
			this->second_position_label->Size = System::Drawing::Size(695, 45);
			this->second_position_label->TabIndex = 18;
			this->second_position_label->Text = L"0 - Player - Date - 0 CZK";
			this->second_position_label->Visible = false;
			// 
			// third_position_label
			// 
			this->third_position_label->BackColor = System::Drawing::Color::Yellow;
			this->third_position_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->third_position_label->Location = System::Drawing::Point(445, 254);
			this->third_position_label->Name = L"third_position_label";
			this->third_position_label->Size = System::Drawing::Size(695, 45);
			this->third_position_label->TabIndex = 19;
			this->third_position_label->Text = L"0 - Player - Date - 0 CZK";
			this->third_position_label->Visible = false;
			// 
			// fourth_position_label
			// 
			this->fourth_position_label->BackColor = System::Drawing::Color::Yellow;
			this->fourth_position_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fourth_position_label->Location = System::Drawing::Point(445, 299);
			this->fourth_position_label->Name = L"fourth_position_label";
			this->fourth_position_label->Size = System::Drawing::Size(695, 45);
			this->fourth_position_label->TabIndex = 20;
			this->fourth_position_label->Text = L"0 - Player - Date - 0 CZK";
			this->fourth_position_label->Visible = false;
			// 
			// fifth_position_label
			// 
			this->fifth_position_label->BackColor = System::Drawing::Color::Yellow;
			this->fifth_position_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fifth_position_label->Location = System::Drawing::Point(444, 344);
			this->fifth_position_label->Name = L"fifth_position_label";
			this->fifth_position_label->Size = System::Drawing::Size(695, 45);
			this->fifth_position_label->TabIndex = 21;
			this->fifth_position_label->Text = L"0 - Player - Date - 0 CZK";
			this->fifth_position_label->Visible = false;
			// 
			// sixth_position_label
			// 
			this->sixth_position_label->BackColor = System::Drawing::Color::Yellow;
			this->sixth_position_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sixth_position_label->Location = System::Drawing::Point(445, 389);
			this->sixth_position_label->Name = L"sixth_position_label";
			this->sixth_position_label->Size = System::Drawing::Size(695, 45);
			this->sixth_position_label->TabIndex = 22;
			this->sixth_position_label->Text = L"0 - Player - Date - 0 CZK";
			this->sixth_position_label->Visible = false;
			// 
			// seventh_position_label
			// 
			this->seventh_position_label->BackColor = System::Drawing::Color::Yellow;
			this->seventh_position_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seventh_position_label->Location = System::Drawing::Point(445, 434);
			this->seventh_position_label->Name = L"seventh_position_label";
			this->seventh_position_label->Size = System::Drawing::Size(695, 45);
			this->seventh_position_label->TabIndex = 23;
			this->seventh_position_label->Text = L"0 - Player - Date - 0 CZK";
			this->seventh_position_label->Visible = false;
			// 
			// eight_position_label
			// 
			this->eight_position_label->BackColor = System::Drawing::Color::Yellow;
			this->eight_position_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eight_position_label->Location = System::Drawing::Point(445, 479);
			this->eight_position_label->Name = L"eight_position_label";
			this->eight_position_label->Size = System::Drawing::Size(695, 45);
			this->eight_position_label->TabIndex = 24;
			this->eight_position_label->Text = L"0 - Player - Date - 0 CZK";
			this->eight_position_label->Visible = false;
			// 
			// ninth_position_label
			// 
			this->ninth_position_label->BackColor = System::Drawing::Color::Yellow;
			this->ninth_position_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ninth_position_label->Location = System::Drawing::Point(445, 524);
			this->ninth_position_label->Name = L"ninth_position_label";
			this->ninth_position_label->Size = System::Drawing::Size(695, 45);
			this->ninth_position_label->TabIndex = 25;
			this->ninth_position_label->Text = L"0 - Player - Date - 0 CZK";
			this->ninth_position_label->Visible = false;
			// 
			// tenth_position_label
			// 
			this->tenth_position_label->BackColor = System::Drawing::Color::Yellow;
			this->tenth_position_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tenth_position_label->Location = System::Drawing::Point(445, 569);
			this->tenth_position_label->Name = L"tenth_position_label";
			this->tenth_position_label->Size = System::Drawing::Size(695, 45);
			this->tenth_position_label->TabIndex = 26;
			this->tenth_position_label->Text = L"0 - Player - Date - 0 CZK";
			this->tenth_position_label->Visible = false;
			// 
			// standings_legend
			// 
			this->standings_legend->BackColor = System::Drawing::Color::Yellow;
			this->standings_legend->Font = (gcnew System::Drawing::Font(L"Cooper Black", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->standings_legend->Location = System::Drawing::Point(474, 105);
			this->standings_legend->Name = L"standings_legend";
			this->standings_legend->Size = System::Drawing::Size(695, 45);
			this->standings_legend->TabIndex = 27;
			this->standings_legend->Text = L"Best Score";
			this->standings_legend->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->standings_legend->Visible = false;
			// 
			// standings_background
			// 
			this->standings_background->BackColor = System::Drawing::Color::Yellow;
			this->standings_background->Location = System::Drawing::Point(405, 83);
			this->standings_background->Name = L"standings_background";
			this->standings_background->Size = System::Drawing::Size(815, 553);
			this->standings_background->TabIndex = 16;
			this->standings_background->TabStop = false;
			this->standings_background->Visible = false;
			// 
			// final_score
			// 
			this->final_score->BackColor = System::Drawing::Color::Yellow;
			this->final_score->Font = (gcnew System::Drawing::Font(L"Cooper Black", 36.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->final_score->Location = System::Drawing::Point(120, 665);
			this->final_score->Name = L"final_score";
			this->final_score->Size = System::Drawing::Size(977, 149);
			this->final_score->TabIndex = 28;
			this->final_score->Text = L"Congratulations";
			this->final_score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->final_score->Click += gcnew System::EventHandler(this, &FA_Millionaire::final_score_Click);
			this->final_score->Visible = false;
			// 
			// FA_Millionaire
			// 
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->final_score);
			this->Controls->Add(this->tenth_position_label);
			this->Controls->Add(this->ninth_position_label);
			this->Controls->Add(this->eight_position_label);
			this->Controls->Add(this->seventh_position_label);
			this->Controls->Add(this->sixth_position_label);
			this->Controls->Add(this->fifth_position_label);
			this->Controls->Add(this->fourth_position_label);
			this->Controls->Add(this->third_position_label);
			this->Controls->Add(this->second_position_label);
			this->Controls->Add(this->first_position_label);
			this->Controls->Add(this->standings_legend);
			this->Controls->Add(this->standings_background);
			this->Controls->Add(this->name_box);
			this->Controls->Add(this->player_name_label);
			this->Controls->Add(this->audience_resoults);
			this->Controls->Add(this->login);
			this->Controls->Add(this->standings);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->new_game);
			this->Controls->Add(this->fa_edition_logo);
			this->Controls->Add(this->audience);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->fifty_fifty);
			this->Controls->Add(this->answer_D);
			this->Controls->Add(this->answer_C);
			this->Controls->Add(this->answer_B);
			this->Controls->Add(this->answer_A);
			this->Controls->Add(this->question);
			this->Controls->Add(this->vitesco_logo);
			this->Controls->Add(this->picturePrizeChart);
			this->Controls->Add(this->question_template);
			this->Controls->Add(this->background);
			this->Controls->Add(this->logo_millionaire);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->Name = L"FA_Millionaire";
			this->Text = L"FA_Millionaire";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturePrizeChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->background))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->question_template))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vitesco_logo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fa_edition_logo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->audience_resoults))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo_millionaire))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->standings_background))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {

			FAMillionaire::FA_Millionaire::SetTimer(100);

			if (FAMillionaire::FA_Millionaire::GetTimer() == 500)
			{
				srand(time(NULL));
				PlaySound(MAKEINTRESOURCE(IDR_WAVE20), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
			}

			if (FAMillionaire::FA_Millionaire::GetTimer() == 1000)
			{
				logo_millionaire->Visible = false;
			}

			if (FAMillionaire::FA_Millionaire::GetTimer() == INTRO_TIME)
			{
				ModifyStandings(true);
			}

			if (next_question)
			{
				if (next_question_timer <= 0)
				{
					Questions::Questions::SelectQuestion();
					SetDefaultState(false);
					SetCorrectQuestionPrizeBackground(false);
					next_question = false;
					answer_selected = false;
				}
				else
					next_question_timer -= 100;
			}

			if (evaluate)
			{
				if (evaluate_timer <= 0)
				{
					if (!Questions::Questions::EvaluateAnswer())
					{
						SetCorrectQuestionPrizeBackground(true);
						ModifyFinalScoreLabel();
						final_score->Visible = true;
					}
					else if (round >= 15)
						game_in_progress = false;
					evaluate = false;
				}
				else
					evaluate_timer -= 100;
			}

			if (answer_flashing)
			{
				if (flashing_timer <= 0)
				{
					if (flash_count > 16)
					{
						answer_flashing = false;
						flash_count = 0;

						if (!(round >= 15))
							FAMillionaire::FA_Millionaire::SetNextQuestion(true);
					}

					if ((flash_count % 2 == 0) && !(flash_count > 12))
					{
						Questions::Questions::FlashAnswerBackground(true, flash_count);
					}
					else
						Questions::Questions::FlashAnswerBackground(false, flash_count);

					flash_count++;
					flashing_timer = 300;
				}
				else
					flashing_timer -= 100;
			}

			if (background_music)
			{
				if (background_music_timer <= 0)
				{
					Questions::Questions::PlayCorrectBackgroundSound();
					background_music = false;
					background_music_timer = 2000;
				}
				else
					background_music_timer -= 100;
			}
		}
		private: System::Void answer_A_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!answer_selected && game_in_progress)
			{
				answer_A->BackColor = System::Drawing::Color::Orange;
				answer_A->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Orange;
				answer_A->BackgroundImage = nullptr;

				selected_answer_pos = 0;
				SetEvaluateTimer(2000);
				answer_selected = true;
				evaluate = true;
			}
		}
		private: System::Void answer_B_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!answer_selected && game_in_progress)
			{
				answer_B->BackColor = System::Drawing::Color::Orange;
				answer_B->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Orange;
				answer_B->BackgroundImage = nullptr;

				selected_answer_pos = 1;
				SetEvaluateTimer(2000);
				answer_selected = true;
				evaluate = true;
			}
		}
		private: System::Void answer_C_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!answer_selected && game_in_progress)
			{
				answer_C->BackColor = System::Drawing::Color::Orange;
				answer_C->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Orange;
				answer_C->BackgroundImage = nullptr;

				selected_answer_pos = 2;
				SetEvaluateTimer(2000);
				answer_selected = true;
				evaluate = true;
			}
		}
		private: System::Void answer_D_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!answer_selected && game_in_progress)
			{
				answer_D->BackColor = System::Drawing::Color::Orange;
				answer_D->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Orange;
				answer_D->BackgroundImage = nullptr;

				selected_answer_pos = 3;
				SetEvaluateTimer(2000);
				answer_selected = true;
				evaluate = true;
			}
		}
		private: System::Void fifty_fifty_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!fifty_fifty_used && !answer_selected && game_in_progress)
			{
				this->fifty_fifty->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(L"FA_Millionaire_0001s_0002_50_50 Used")));
				Questions::Questions::FiftyFifty();
				fifty_fifty_used = true;
			}
		}
		private: System::Void phone_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!phone_used && !answer_selected && game_in_progress)
			{
				phone->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(L"FA_Millionaire_0001s_0004_Phone Used")));
				phone_used = true;

				Questions::Questions::GetPhoneHelp();
			}
		}
		private: System::Void audience_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (!audience_used && !answer_selected && game_in_progress)
			{
				audience->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(L"FA_Millionaire_0001s_0000_Audience Used")));
				audience_used = true;

				audience_resoults->Image = (cli::safe_cast<System::Drawing::Image^>(resources_fa_millionaire->GetObject(Questions::Questions::GetAudienceHelp())));
				audience_resoults->Visible = true;
			}
		}
		private: System::Void new_game_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (login_success == false)
				return;

			SetDefaultState(true);
			Questions::Questions::StartNewGame();
		}
		private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Application::Exit();
		}
		private: System::Void login_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (name_box->Text == "...Insert Name..." || name_box->Text == "")
				return;

			if (login->Text == "Login")
			{
				login->Text = "End Game";
				name_box->Visible = false;
				final_score->Visible = false;
				player_name_label->Text = "Player: " + name_box->Text;
				player_name_label->Visible = true;
				float label_size = 28;
				if (player_name_label->Text->Length >= 5)
				{
					label_size -= (2.0f * (player_name_label->Text->Length / 4));
					player_name_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", label_size, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					player_name_label->Location = System::Drawing::Point(1229, 22);
				}
				else
					player_name_label->Font = (gcnew System::Drawing::Font(L"Cooper Black", label_size, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));

				SetDefaultState(false);
				answer_A->Text = "";
				answer_B->Text = "";
				answer_C->Text = "";
				answer_D->Text = "";
				question->Text = "";

				login_success = true;
			}
			else if (login->Text == "End Game")
			{
				login->Text = "Login";
				player_name_label->Visible = false;
				name_box->Text = "...Insert Name...";
				name_box->Visible = true;
				login_success = false;

				// Decrease round so the final data for standings are taken from previous round (round, money)
				// with exception for the first round
				if (round != 0)
					round--;

				// Prevent duplicit saving when player selects wrong answer (it is already modified there)
				if (game_in_progress)
				{
					selected_answer_pos = -1;
					Questions::Questions::EvaluateAnswer();
					SetCorrectQuestionPrizeBackground(false);
				}

				// Show final score
				ModifyFinalScoreLabel();
				final_score->Visible = true;

				game_in_progress = false;
			}
		}
		private: System::Void name_box_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			name_box->Text = "";
		}
		private: System::Void standings_Click(System::Object^ sender, System::EventArgs^ e) 
		{ 
			if (standings_shown == false)
				standings_shown = true;
			else
				standings_shown = false;

			std::vector<std::wstring> standings = GetStandingsInput();
			cliext::vector<System::String^> new_standings;
			int i = 0;

			if (!standings.empty())
			{
				for (std::vector<std::wstring>::iterator itr = standings.begin(); itr != standings.end(); ++itr)
				{
					new_standings.push_back(gcnew String(standings[i].c_str()));
					i++;
				}
			}

			while (i < 10)
			{
				new_standings.push_back("0 - Player - Date - 0 CZK");
			}
			
			standings_background->Visible = standings_shown;
			standings_legend->Visible = standings_shown;
			standings_legend->BringToFront();
			first_position_label->Text = new_standings[0];
			first_position_label->Visible = standings_shown;
			first_position_label->BringToFront();
			second_position_label->Text = new_standings[1];
			second_position_label->Visible = standings_shown;
			second_position_label->BringToFront();
			third_position_label->Text = new_standings[2];
			third_position_label->Visible = standings_shown;
			third_position_label->BringToFront();
			fourth_position_label->Text = new_standings[3];
			fourth_position_label->Visible = standings_shown;
			fourth_position_label->BringToFront();
			fifth_position_label->Text = new_standings[4];
			fifth_position_label->Visible = standings_shown;
			fifth_position_label->BringToFront();
			sixth_position_label->Text = new_standings[5];
			sixth_position_label->Visible = standings_shown;
			sixth_position_label->BringToFront();
			seventh_position_label->Text = new_standings[6];
			seventh_position_label->Visible = standings_shown;
			seventh_position_label->BringToFront();
			eight_position_label->Text = new_standings[7];
			eight_position_label->Visible = standings_shown;
			eight_position_label->BringToFront();
			ninth_position_label->Text = new_standings[8];
			ninth_position_label->Visible = standings_shown;
			ninth_position_label->BringToFront();
			tenth_position_label->Text = new_standings[9];
			tenth_position_label->Visible = standings_shown;
			tenth_position_label->BringToFront();
		}
		private: System::Void final_score_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (final_score->Visible == true)
				final_score->Visible = false;
			else
				final_score->Visible = true;
		}
};
}
