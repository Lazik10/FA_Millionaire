#pragma once

namespace FAMillionaire {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int INTRO_TIME = 39000;

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
	private: System::Windows::Forms::Button^ answer_A;
	private: System::Windows::Forms::Button^ answer_B;
	private: System::Windows::Forms::Button^ answer_C;
	private: System::Windows::Forms::Button^ answer_D;
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
	private: System::Windows::Forms::Label^ question;

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
			this->question->ForeColor = System::Drawing::Color::Transparent;
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
			this->answer_A->Location = System::Drawing::Point(94, 489);
			this->answer_A->Name = L"answer_A";
			this->answer_A->Size = System::Drawing::Size(243, 36);
			this->answer_A->TabIndex = 5;
			this->answer_A->Text = L"A: answer";
			this->answer_A->UseVisualStyleBackColor = true;
			// 
			// answer_B
			// 
			this->answer_B->Location = System::Drawing::Point(466, 489);
			this->answer_B->Name = L"answer_B";
			this->answer_B->Size = System::Drawing::Size(243, 36);
			this->answer_B->TabIndex = 5;
			this->answer_B->Text = L"B: answer";
			this->answer_B->UseVisualStyleBackColor = true;
			// 
			// answer_C
			// 
			this->answer_C->Location = System::Drawing::Point(94, 541);
			this->answer_C->Name = L"answer_C";
			this->answer_C->Size = System::Drawing::Size(243, 36);
			this->answer_C->TabIndex = 5;
			this->answer_C->Text = L"C: answer";
			this->answer_C->UseVisualStyleBackColor = true;
			// 
			// answer_D
			// 
			this->answer_D->Location = System::Drawing::Point(466, 541);
			this->answer_D->Name = L"answer_D";
			this->answer_D->Size = System::Drawing::Size(243, 36);
			this->answer_D->TabIndex = 5;
			this->answer_D->Text = L"D: answer";
			this->answer_D->UseVisualStyleBackColor = true;
			// 
			// fifty_fifty
			// 
			this->fifty_fifty->Location = System::Drawing::Point(865, 13);
			this->fifty_fifty->Name = L"fifty_fifty";
			this->fifty_fifty->Size = System::Drawing::Size(134, 95);
			this->fifty_fifty->TabIndex = 6;
			this->fifty_fifty->Text = L"50:50";
			this->fifty_fifty->UseVisualStyleBackColor = true;
			// 
			// phone
			// 
			this->phone->Location = System::Drawing::Point(1020, 12);
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(134, 95);
			this->phone->TabIndex = 6;
			this->phone->Text = L"phone";
			this->phone->UseVisualStyleBackColor = true;
			// 
			// audience
			// 
			this->audience->Location = System::Drawing::Point(1169, 12);
			this->audience->Name = L"audience";
			this->audience->Size = System::Drawing::Size(134, 95);
			this->audience->TabIndex = 6;
			this->audience->Text = L"audience";
			this->audience->UseVisualStyleBackColor = true;
			// 
			// FA_Millionaire
			// 
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1366, 724);
			//this->axWindowsMediaPlayer1->Size = System::Drawing::Size(FAMillionaire::FA_Millionaire::GetDesktopResolution(true),
			//	FAMillionaire::FA_Millionaire::GetDesktopResolution(false));
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

		if (FAMillionaire::FA_Millionaire::GetTimer() == 37000 /*INTRO_TIME*/)
		{
			/*FAMillionaire::FA_Millionaire::*/axWindowsMediaPlayer1->close();
			/*FAMillionaire::FA_Millionaire::*/axWindowsMediaPlayer1->Hide();
		}
	}
};
}
