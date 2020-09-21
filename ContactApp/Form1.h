#pragma once
#include "g.h"
#include "Sound\\PlaySound.h"
#include<Windows.h>
#include<stdio.h>
#include<sstream>
#include "Testing\\digit_recognisation.h"
#include "Database\\contact_reader.h"
#include<tchar.h>

namespace ContactApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	//using namespace System.ComponentModel.Browsable(false)

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		public: static Form1 ^obj;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			CheckForIllegalCrossThreadCalls=false;
			obj=this;
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::SplitContainer^  splitContainer4;
	private: System::Windows::Forms::SplitContainer^  splitContainer3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	std::wstring s2ws(const std::string& s)
	{
	    int len;
	    int slength = (int)s.length() + 1;
	    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
	    wchar_t* buf = new wchar_t[len];
	    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	    std::wstring r(buf);
	    delete[] buf;
	    return r;
	}
	static void fg()
	{
		char buff[100];
		
		//MessageBoxA ( NULL, "Wait for 3 sec", "Test", MB_OK );

		//Thread^ thread = gcnew Thread(gcnew ThreadStart(&play));
		//		 thread->Start();
		//name=-1;
		obj->label1->Text = L"Contact Search App\n\nWelcomes you";
		play();
		obj->label6->Text = L"Next event in 3 sec";
		Sleep(1000);
		obj->label6->Text = L"Next event in 2 sec";
		Sleep(1000);
		obj->label6->Text = L"Next event in 1 sec";
		Sleep(1000);
		obj->label6->Text = L"Enjoy the moment";
		
		string l3;
		//=========Working Click listener===================//
		//obj->button3->PerformClick();
		
		while(1)
		{
			obj->label3->Text = L"Speak the contact name!!";
			audio_speak_the_word();
			int n=hmm();
			//std::string test1 = std::to_string((long double)n);
			//MessageBoxA ( NULL, test1.c_str(), "Test", MB_OK );
			string name=getname(n);
			l3= "Contact name detected as " + name+ ".\nIs it correct?";
			String^ str3=gcnew String(l3.c_str());
			obj->label3->Text = str3;
			audio_name_detected_as_name(n);
			audio_is_it_correct();
			int n2=hmm2();

			if(n2==17) //yes case
			{
				l3= "Fetching details of "+ name;
				str3=gcnew String(l3.c_str());
				obj->label3->Text = str3;
				vector<string> record= read_contact_address(n);
				string displaydata= record[0] + "\n" + record[1] + "\n" + record[2] + "\n" + record[3];
				String^ str=gcnew String(displaydata.c_str());
				obj->label4->Text = str;
				l3= "Showing details of "+ name;
				str3=gcnew String(l3.c_str());
				obj->label3->Text = str3;
				audio_showing_details_of_name(n);
				obj->label6->Text = L"Your next search is coming in 10 sec";
				Sleep(1000);
				obj->label6->Text = L"Your next search is coming in 9 sec";
				Sleep(1000);
				obj->label6->Text = L"Your next search is coming in 8 sec";
				Sleep(1000);
				obj->label6->Text = L"Your next search is coming in 7 sec";
				Sleep(1000);
				obj->label6->Text = L"Your next search is coming in 6 sec";
				Sleep(1000);
				obj->label6->Text = L"Your next search is coming in 5 sec";
				Sleep(1000);
				obj->label6->Text = L"Your next search is coming in 4 sec";
				Sleep(1000);
				obj->label6->Text = L"Your next search is coming in 3 sec";
				Sleep(1000);
				obj->label6->Text = L"Your next search is coming in 2 sec";
				Sleep(1000);
				obj->label6->Text = L"Your next search is coming in 1 sec";
				Sleep(1000);
				obj->label6->Text = L"Enjoy the moment";
				while(1)
				{
					//Do you want to search again
					l3= "Do you want to search again?";
					audio_do_you_want_to_search_contact_again();
					String^ str3=gcnew String(l3.c_str());
					obj->label3->Text = str3;
					obj->label4->Text = L"";
					int n3=hmm2();
					if(n3==17) break; //yes case
					if(n3==18)
					{
						obj->label6->Text = L"About to leave in 5 sec";
						Sleep(1000);
						obj->label6->Text = L"About to leave in 4 sec";
						Sleep(1000);
						obj->label6->Text = L"About to leave in 3 sec";
						Sleep(1000);
						obj->label6->Text = L"About to leave in 2 sec";
						Sleep(1000);
						obj->label6->Text = L"About to leave in 1 sec";
						Sleep(1000);
						obj->label6->Text = L"Enjoy the moment";
						Application::Exit();

					}
					if(n3==19) 
					{
						obj->label6->Text = L"Application is waiting: 5 sec";
						Sleep(1000);
						obj->label6->Text = L"Application is waiting:  4 sec";
						Sleep(1000);
						obj->label6->Text = L"Application is waiting: 3 sec";
						Sleep(1000);
						obj->label6->Text = L"Application is waiting: 2 sec";
						Sleep(1000);
						obj->label6->Text = L"Application is waiting: 1 sec";
						Sleep(1000);
					}
					//if no exit
					//if hold , 5 sec pause
				}
			}
			//std::string test1 = std::to_string((long double)n);
			//MessageBoxA ( NULL, test1.c_str(), "Test", MB_OK );
			
			if(n2==18) continue;
		}
		
		
		
		//obj->button3_Click(obj,&Form1::button3_Click);
		//this, &Form1::button3_Click
		//button3_Click(System::Object^  sender, System::EventArgs^  e)
		//setLabel(obj);
		//name=hmm();
		//int n=hmm();
		//int n=2;
		//ostringstream str1;
		//str1.str("");
		//str1<<n;
		//String ^str3=gcnew String(str1.str().c_str());


		//----
		//std::string test1 = std::to_string((long double)n);
		//MessageBoxA ( NULL, test1.c_str(), "Test", MB_OK );
		//obj->set_label1(obj);
		//this->label1->Text = L"YOu are too good";
		/*
		sleep(1000);
		MessageBoxA ( NULL, "Wait for 2 sec", "Test", MB_OK );
		sleep(1000);
		MessageBoxA ( NULL, "Wait for 2 sec", "Test", MB_OK );*/
		//MessageBox(hWnd, buff, "Msg title", MB_OK | MB_ICONQUESTION);
	}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer4 = (gcnew System::Windows::Forms::SplitContainer());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer4))->BeginInit();
			this->splitContainer4->Panel1->SuspendLayout();
			this->splitContainer4->Panel2->SuspendLayout();
			this->splitContainer4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->BackColor = System::Drawing::Color::Transparent;
			this->splitContainer1->Panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"splitContainer1.Panel2.BackgroundImage")));
			this->splitContainer1->Panel2->Controls->Add(this->label2);
			this->splitContainer1->Panel2->Controls->Add(this->button3);
			this->splitContainer1->Panel2->Controls->Add(this->button2);
			this->splitContainer1->Panel2->Controls->Add(this->button1);
			this->splitContainer1->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel2_Paint);
			this->splitContainer1->Size = System::Drawing::Size(1029, 543);
			this->splitContainer1->SplitterDistance = 444;
			this->splitContainer1->TabIndex = 0;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->splitContainer4);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->splitContainer3);
			this->splitContainer2->Size = System::Drawing::Size(1029, 444);
			this->splitContainer2->SplitterDistance = 294;
			this->splitContainer2->TabIndex = 0;
			// 
			// splitContainer4
			// 
			this->splitContainer4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer4->Location = System::Drawing::Point(0, 0);
			this->splitContainer4->Name = L"splitContainer4";
			this->splitContainer4->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer4.Panel1
			// 
			this->splitContainer4->Panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->splitContainer4->Panel1->Controls->Add(this->label1);
			this->splitContainer4->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer4_Panel1_Paint);
			// 
			// splitContainer4.Panel2
			// 
			this->splitContainer4->Panel2->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->splitContainer4->Panel2->Controls->Add(this->label6);
			this->splitContainer4->Panel2->Controls->Add(this->label5);
			this->splitContainer4->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer4_Panel2_Paint);
			this->splitContainer4->Size = System::Drawing::Size(294, 444);
			this->splitContainer4->SplitterDistance = 347;
			this->splitContainer4->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(25, 39);
			this->label1->MaximumSize = System::Drawing::Size(250, 250);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(28, 43);
			this->label6->MaximumSize = System::Drawing::Size(300, 300);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(184, 17);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Getting things ready for you";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(106, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 24);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Status";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Name = L"splitContainer3";
			this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->BackColor = System::Drawing::SystemColors::Info;
			this->splitContainer3->Panel1->Controls->Add(this->label3);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->label4);
			this->splitContainer3->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer3_Panel2_Paint);
			this->splitContainer3->Size = System::Drawing::Size(731, 444);
			this->splitContainer3->SplitterDistance = 128;
			this->splitContainer3->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(170, 44);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(210, 26);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Listen to instructions";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Rockwell", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(182, 78);
			this->label4->MaximumSize = System::Drawing::Size(400, 400);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 25);
			this->label4->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Cursor = System::Windows::Forms::Cursors::No;
			this->label2->Font = (gcnew System::Drawing::Font(L"Pristina", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(435, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(174, 35);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Navigation Zone";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(373, 60);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Home";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(480, 60);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(589, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(1029, 543);
			this->Controls->Add(this->splitContainer1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Voice Based Contact Search App";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->splitContainer4->Panel1->ResumeLayout(false);
			this->splitContainer4->Panel1->PerformLayout();
			this->splitContainer4->Panel2->ResumeLayout(false);
			this->splitContainer4->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer4))->EndInit();
			this->splitContainer4->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel1->PerformLayout();
			this->splitContainer3->Panel2->ResumeLayout(false);
			this->splitContainer3->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		
#pragma endregion
		public: System::Void set_label1(Form1 ^ob)
		{
			ob->label1->Text = L"Label changed for you";
		}
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 //play();
				 //sleep();
				 Thread^ thread = gcnew Thread(gcnew ThreadStart(&fg));
				 thread->Start();
			 }
	private: System::Void Form1_Activated(System::Object^  sender, System::EventArgs^  e)
			{
					this->label1->Text = L"Label changed for you";
			}
			
	private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e)
			{
					
					// If MyThreadFunc is an instance method, use "gcnew ThreadStart(this, &ClassName::MyThreadFunc)" to get the delegate.
					
			}
	private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				Application::Restart();			 
				 
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //demo();
			 //player();
			//play();
			 //fg();
			// Thread^ thread = gcnew Thread(gcnew ThreadStart(&fg));
			//	 thread->Start();
			Application::Exit();
		 }
private: System::Void splitContainer4_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
		 {
			 
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			demo();			 //brun();
		 }
private: System::Void splitContainer4_Panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void splitContainer1_Panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void splitContainer3_Panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void progressBar1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};


}


