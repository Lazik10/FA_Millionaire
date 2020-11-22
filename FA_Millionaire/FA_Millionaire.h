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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->question = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->answer_A = (gcnew System::Windows::Forms::Button());
			this->answer_B = (gcnew System::Windows::Forms::Button());
			this->answer_C = (gcnew System::Windows::Forms::Button());
			this->answer_D = (gcnew System::Windows::Forms::Button());
			this->fifty_fifty = (gcnew System::Windows::Forms::Button());
			this->phone = (gcnew System::Windows::Forms::Button());
			this->audience = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturePrizeChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// picturePrizeChart
			// 
			this->picturePrizeChart->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picturePrizeChart.Image")));
			this->picturePrizeChart->Location = System::Drawing::Point(804, 114);
			this->picturePrizeChart->Name = L"picturePrizeChart";
			this->picturePrizeChart->Size = System::Drawing::Size(570, 463);
			this->picturePrizeChart->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
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
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(811, 382);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 378);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(811, 199);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// question
			// 
			this->question->BackColor = System::Drawing::Color::Transparent;
			this->question->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->question->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->question->ForeColor = System::Drawing::Color::Yellow;
			this->question->Location = System::Drawing::Point(90, 396);
			this->question->Name = L"question";
			this->question->Size = System::Drawing::Size(619, 68);
			this->question->TabIndex = 4;
			this->question->Text = L"Question";
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &FA_Millionaire::timer_Tick);
			// 
			// answer_A
			// 
			this->answer_A->BackColor = System::Drawing::Color::Transparent;
			this->answer_A->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->answer_A->FlatAppearance->BorderSize = 0;
			this->answer_A->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_A->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_A->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->answer_A->Location = System::Drawing::Point(85, 489);
			this->answer_A->Name = L"answer_A";
			this->answer_A->Size = System::Drawing::Size(252, 36);
			this->answer_A->TabIndex = 5;
			this->answer_A->Text = L"A: answer";
			this->answer_A->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_A->UseVisualStyleBackColor = false;
			this->answer_A->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_A_Click);
			// 
			// answer_B
			// 
			this->answer_B->BackColor = System::Drawing::Color::Transparent;
			this->answer_B->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->answer_B->FlatAppearance->BorderSize = 0;
			this->answer_B->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_B->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_B->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->answer_B->Location = System::Drawing::Point(466, 489);
			this->answer_B->Name = L"answer_B";
			this->answer_B->Size = System::Drawing::Size(243, 36);
			this->answer_B->TabIndex = 5;
			this->answer_B->Text = L"B: answer";
			this->answer_B->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_B->UseVisualStyleBackColor = true;
			this->answer_B->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_B_Click);
			// 
			// answer_C
			// 
			this->answer_C->BackColor = System::Drawing::Color::Transparent;
			this->answer_C->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->answer_C->FlatAppearance->BorderSize = 0;
			this->answer_C->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_C->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_C->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->answer_C->Location = System::Drawing::Point(94, 541);
			this->answer_C->Name = L"answer_C";
			this->answer_C->Size = System::Drawing::Size(243, 36);
			this->answer_C->TabIndex = 5;
			this->answer_C->Text = L"C: answer";
			this->answer_C->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_C->UseVisualStyleBackColor = true;
			this->answer_C->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_C_Click);
			// 
			// answer_D
			// 
			this->answer_D->BackColor = System::Drawing::Color::Transparent;
			this->answer_D->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->answer_D->FlatAppearance->BorderSize = 0;
			this->answer_D->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->answer_D->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->answer_D->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->answer_D->Location = System::Drawing::Point(466, 541);
			this->answer_D->Name = L"answer_D";
			this->answer_D->Size = System::Drawing::Size(243, 36);
			this->answer_D->TabIndex = 5;
			this->answer_D->Text = L"D: answer";
			this->answer_D->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->answer_D->UseVisualStyleBackColor = true;
			this->answer_D->Click += gcnew System::EventHandler(this, &FA_Millionaire::answer_D_Click);
			// 
			// fifty_fifty
			// 
			this->fifty_fifty->Location = System::Drawing::Point(865, 13);
			this->fifty_fifty->Name = L"fifty_fifty";
			this->fifty_fifty->Size = System::Drawing::Size(134, 95);
			this->fifty_fifty->TabIndex = 6;
			this->fifty_fifty->Text = L"50:50";
			this->fifty_fifty->UseVisualStyleBackColor = true;
			this->fifty_fifty->Click += gcnew System::EventHandler(this, &FA_Millionaire::fifty_fifty_Click);
			// 
			// phone
			// 
			this->phone->Location = System::Drawing::Point(1020, 12);
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(134, 95);
			this->phone->TabIndex = 6;
			this->phone->Text = L"phone";
			this->phone->UseVisualStyleBackColor = true;
			this->phone->Click += gcnew System::EventHandler(this, &FA_Millionaire::phone_Click);
			// 
			// audience
			// 
			this->audience->Location = System::Drawing::Point(1169, 12);
			this->audience->Name = L"audience";
			this->audience->Size = System::Drawing::Size(134, 95);
			this->audience->TabIndex = 6;
			this->audience->Text = L"audience";
			this->audience->UseVisualStyleBackColor = true;
			this->audience->Click += gcnew System::EventHandler(this, &FA_Millionaire::audience_Click);
			// 
			// FA_Millionaire
			// 
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1366, 724);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Controls->Add(this->audience);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->fifty_fifty);
			this->Controls->Add(this->answer_D);
			this->Controls->Add(this->answer_C);
			this->Controls->Add(this->answer_B);
			this->Controls->Add(this->answer_A);
			this->Controls->Add(this->question);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->picturePrizeChart);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->Name = L"FA_Millionaire";
			this->Text = L"FA_Millionaire";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturePrizeChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
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
		private: System::Void answer_C_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void answer_B_Click(System::Object^ sender, System::EventArgs^ e) {
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
