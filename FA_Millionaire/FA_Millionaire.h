#pragma once
#include "Questions.h"

namespace FAMillionaire {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int INTRO_TIME = 15000;

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
	public: static System::Windows::Forms::Button^ answer_A;
	public: static System::Windows::Forms::Button^ answer_B;
	public: static System::Windows::Forms::Button^ answer_C;
	public: static System::Windows::Forms::Button^ answer_D;
	public: static System::Windows::Forms::Label^ question;

	private: System::Windows::Forms::Button^ fifty_fifty;
	private: System::Windows::Forms::Button^ phone;
	private: System::Windows::Forms::Button^ audience;
	private: System::Windows::Forms::PictureBox^ vitesco_logo;
	private: System::Windows::Forms::PictureBox^ fa_edition_logo;

	public: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer1;
	public:

		static int GetTimer();
		static void SetTimer(int diff);
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
	//private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer1;
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

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FA_Millionaire::typeid));
			this->picturePrizeChart = (gcnew System::Windows::Forms::PictureBox());
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturePrizeChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->background))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->question_template))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vitesco_logo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fa_edition_logo))->BeginInit();
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
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(0, -1);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(0, 0);
			this->axWindowsMediaPlayer1->TabIndex = 0;
			// 
			// background
			// 
			this->background->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->background->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"background.Image")));
			this->background->Location = System::Drawing::Point(-1, 35);
			this->background->Name = L"background";
			this->background->Size = System::Drawing::Size(1234, 612);
			this->background->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->background->TabIndex = 2;
			this->background->TabStop = false;
			// 
			// question_template
			// 
			this->question_template->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"question_template.Image")));
			this->question_template->Location = System::Drawing::Point(-1, 701);
			this->question_template->Name = L"question_template";
			this->question_template->Size = System::Drawing::Size(1234, 330);
			this->question_template->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->question_template->TabIndex = 3;
			this->question_template->TabStop = false;
			// 
			// question
			// 
			this->question->BackColor = System::Drawing::Color::Transparent;
			this->question->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->question->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->question->ForeColor = System::Drawing::Color::Silver;
			this->question->Location = System::Drawing::Point(88, 691);
			this->question->Name = L"question";
			this->question->Size = System::Drawing::Size(1035, 110);
			this->question->TabIndex = 4;
			this->question->Text = L"Question";
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
			this->answer_A->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->answer_A->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->answer_A->FlatAppearance->BorderSize = 0;
			this->answer_A->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->answer_A->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->answer_A->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->answer_A->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_A->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_A->ForeColor = System::Drawing::Color::Silver;
			this->answer_A->Location = System::Drawing::Point(144, 863);
			this->answer_A->Name = L"answer_A";
			this->answer_A->Size = System::Drawing::Size(356, 47);
			this->answer_A->TabIndex = 5;
			this->answer_A->Text = L"answer";
			this->answer_A->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_A->UseVisualStyleBackColor = false;
			this->answer_A->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_A_Click);
			// 
			// answer_B
			// 
			this->answer_B->BackColor = System::Drawing::Color::Transparent;
			this->answer_B->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"answer_B.BackgroundImage")));
			this->answer_B->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->answer_B->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->answer_B->FlatAppearance->BorderSize = 0;
			this->answer_B->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->answer_B->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->answer_B->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->answer_B->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_B->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_B->ForeColor = System::Drawing::Color::Silver;
			this->answer_B->Location = System::Drawing::Point(790, 863);
			this->answer_B->Name = L"answer_B";
			this->answer_B->Size = System::Drawing::Size(355, 47);
			this->answer_B->TabIndex = 5;
			this->answer_B->Text = L"answer";
			this->answer_B->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_B->UseVisualStyleBackColor = true;
			this->answer_B->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_B_Click);
			// 
			// answer_C
			// 
			this->answer_C->BackColor = System::Drawing::Color::Transparent;
			this->answer_C->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"answer_C.BackgroundImage")));
			this->answer_C->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->answer_C->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->answer_C->FlatAppearance->BorderSize = 0;
			this->answer_C->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->answer_C->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->answer_C->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->answer_C->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_C->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_C->ForeColor = System::Drawing::Color::Silver;
			this->answer_C->Location = System::Drawing::Point(144, 941);
			this->answer_C->Name = L"answer_C";
			this->answer_C->Size = System::Drawing::Size(356, 49);
			this->answer_C->TabIndex = 5;
			this->answer_C->Text = L"answer";
			this->answer_C->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_C->UseVisualStyleBackColor = true;
			this->answer_C->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_C_Click);
			// 
			// answer_D
			// 
			this->answer_D->BackColor = System::Drawing::Color::Transparent;
			this->answer_D->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"answer_D.BackgroundImage")));
			this->answer_D->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->answer_D->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->answer_D->FlatAppearance->BorderSize = 0;
			this->answer_D->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->answer_D->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->answer_D->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->answer_D->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_D->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_D->ForeColor = System::Drawing::Color::Silver;
			this->answer_D->Location = System::Drawing::Point(790, 941);
			this->answer_D->Name = L"answer_D";
			this->answer_D->Size = System::Drawing::Size(355, 49);
			this->answer_D->TabIndex = 5;
			this->answer_D->Text = L"answer";
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
			this->vitesco_logo->Location = System::Drawing::Point(-1, 0);
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
			// FA_Millionaire
			// 
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->fa_edition_logo);
			this->Controls->Add(this->axWindowsMediaPlayer1);
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
			this->Controls->Add(this->background);
			this->Controls->Add(this->question_template);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->Name = L"FA_Millionaire";
			this->Text = L"FA_Millionaire";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturePrizeChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->background))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->question_template))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vitesco_logo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fa_edition_logo))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {

			FAMillionaire::FA_Millionaire::SetTimer(100);

			if (FAMillionaire::FA_Millionaire::GetTimer() == 500)
			{
				axWindowsMediaPlayer1->fullScreen = true;
			}

			if (FAMillionaire::FA_Millionaire::GetTimer() == 17000 /*INTRO_TIME*/)
			{
				axWindowsMediaPlayer1->close();
				axWindowsMediaPlayer1->Hide();
				Questions::Questions::StartGame();
			}
		}
		private: System::Void answer_A_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void answer_B_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void answer_C_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void answer_D_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void fifty_fifty_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void phone_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void audience_Click(System::Object^ sender, System::EventArgs^ e) {
		}
	};
}
