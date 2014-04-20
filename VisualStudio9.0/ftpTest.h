#pragma once

#include "Poco/Net/FTPClientSession.h"
#include "Poco/Net/DialogSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/NetException.h"
#include "Poco/Thread.h"
#include "Poco/ActiveMethod.h"
#include "Poco/StreamCopier.h"

#include "Poco/NullStream.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "Poco/Exception.h"

#include <string>
#include <iostream>
#include <sstream>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace std;

using Poco::Net::FTPClientSession;			// FTP
using Poco::Net::DialogSocket;
using Poco::Net::SocketAddress;
using Poco::Net::FTPException;
using Poco::ActiveMethod;
using Poco::ActiveResult;
using Poco::StreamCopier;
using Poco::Thread;



namespace ftpTest {

	/// <summary>
	/// Summary for frmFTPTest
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class frmFTPTest : public System::Windows::Forms::Form
	{
	public:
		frmFTPTest(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmFTPTest()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  btnSend;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxServer;
	private: System::Windows::Forms::TextBox^  textBoxUserName;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBoxPassWord;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBoxFileName;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBoxLog;
	private: System::Windows::Forms::ComboBox^  comboBoxAction;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnBrowseFile;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialogUpload;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxServer = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUserName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxPassWord = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxFileName = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxLog = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxAction = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnBrowseFile = (gcnew System::Windows::Forms::Button());
			this->openFileDialogUpload = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// btnSend
			// 
			this->btnSend->Location = System::Drawing::Point(546, 295);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(75, 32);
			this->btnSend->TabIndex = 0;
			this->btnSend->Text = L"Send";
			this->btnSend->UseVisualStyleBackColor = true;
			this->btnSend->Click += gcnew System::EventHandler(this, &frmFTPTest::btnSend_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Server:";
			// 
			// textBoxServer
			// 
			this->textBoxServer->Location = System::Drawing::Point(34, 46);
			this->textBoxServer->Name = L"textBoxServer";
			this->textBoxServer->Size = System::Drawing::Size(189, 20);
			this->textBoxServer->TabIndex = 2;
			// 
			// textBoxUserName
			// 
			this->textBoxUserName->Location = System::Drawing::Point(34, 95);
			this->textBoxUserName->Name = L"textBoxUserName";
			this->textBoxUserName->Size = System::Drawing::Size(189, 20);
			this->textBoxUserName->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Username:";
			// 
			// textBoxPassWord
			// 
			this->textBoxPassWord->Location = System::Drawing::Point(34, 143);
			this->textBoxPassWord->Name = L"textBoxPassWord";
			this->textBoxPassWord->Size = System::Drawing::Size(189, 20);
			this->textBoxPassWord->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(31, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Password:";
			// 
			// textBoxFileName
			// 
			this->textBoxFileName->Location = System::Drawing::Point(66, 280);
			this->textBoxFileName->Name = L"textBoxFileName";
			this->textBoxFileName->Size = System::Drawing::Size(342, 20);
			this->textBoxFileName->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(31, 261);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"File name:";
			// 
			// textBoxLog
			// 
			this->textBoxLog->Location = System::Drawing::Point(229, 46);
			this->textBoxLog->Multiline = true;
			this->textBoxLog->Name = L"textBoxLog";
			this->textBoxLog->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxLog->Size = System::Drawing::Size(392, 228);
			this->textBoxLog->TabIndex = 9;
			// 
			// comboBoxAction
			// 
			this->comboBoxAction->FormattingEnabled = true;
			this->comboBoxAction->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Download", L"Upload", L"Delete", L"List files", 
				L"List folders", L"Set directory"});
			this->comboBoxAction->Location = System::Drawing::Point(34, 192);
			this->comboBoxAction->Name = L"comboBoxAction";
			this->comboBoxAction->Size = System::Drawing::Size(121, 21);
			this->comboBoxAction->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(31, 176);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Action:";
			// 
			// btnBrowseFile
			// 
			this->btnBrowseFile->Location = System::Drawing::Point(34, 277);
			this->btnBrowseFile->Name = L"btnBrowseFile";
			this->btnBrowseFile->Size = System::Drawing::Size(26, 22);
			this->btnBrowseFile->TabIndex = 12;
			this->btnBrowseFile->Text = L"...";
			this->btnBrowseFile->UseVisualStyleBackColor = true;
			this->btnBrowseFile->Click += gcnew System::EventHandler(this, &frmFTPTest::btnBrowseFile_Click);
			// 
			// frmFTPTest
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 339);
			this->Controls->Add(this->btnBrowseFile);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBoxAction);
			this->Controls->Add(this->textBoxLog);
			this->Controls->Add(this->textBoxFileName);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxPassWord);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxUserName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxServer);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnSend);
			this->Name = L"frmFTPTest";
			this->Text = L"FTP Client Test";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// ==========================================================================
// Convert String^ to string (Standard string)
//
// string a;
// String^ c;
// MarshalString(c, a);
// ==========================================================================
void MarshalString ( String ^ s, string& os ) 
{
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();

	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

// ==========================================================================
// Convert String^ to wstring
//
// string a;
// String^ c;
// MarshalString(c, a);
// ==========================================================================
void MarshalString ( String ^ s, wstring& os ) 
{
	using namespace Runtime::InteropServices;
	const wchar_t* chars = 
	(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

// Send button - clicked
private: System::Void btnSend_Click(System::Object^  sender, System::EventArgs^  e) 
 {
	 string serverAddress = "vnelek.vn";
	 string username = "vnelekvn";
	 string password = "bkdanangvietnam13";
	 
	 char buffer[100];
	 char *pData = buffer;
	 

	 // Convert address from textbox to standard string
	 //MarshalString(textBoxServer->Text, serverAddress);
	 
	 try
	 {
		 // Create new session
		 FTPClientSession mySession(serverAddress);
		 
		 // Login
		 mySession.login(username, password);

		 // Remove file
		 mySession.remove("abc/hello.txt");

		 // Rename
		 //mySession.rename("hello.txt", "ab.dat");

		 // Create directory
		 //mySession.createDirectory("/xinchao");

		 // Delete directory
		 //mySession.removeDirectory("/xinchao");

		 // Set working directory
		 //mySession.setWorkingDirectory("/public_html");

		 // Get working directory
		 //string txt = mySession.getWorkingDirectory();
		 //textBoxLog->Text = gcnew String(txt.c_str());
		 
		 // List directories & files
		//string received;
		//std::istream& istr = mySession.beginList(txt);
		//std::ostringstream ostr;
		//StreamCopier::copyStream(istr, ostr);
		//mySession.endList();
		//received = ostr.str();
		//textBoxLog->Text = gcnew String(received.c_str());


		 // Download file
		//string received;
		std::istream& istr = mySession.beginDownload("hello.txt");
		//std::ostringstream ostr;
		//StreamCopier::copyStream(istr, ostr);
		//mySession.endDownload();
		//received = ostr.str();
		//textBoxLog->Text = gcnew String(received.c_str());

		 // Upload file		 		 
		 std::ostream& ostr = mySession.beginUpload("hello.txt");
		 ostr<< "Xin chao Vietnam!\r\n";
		 ostr<< "End of file content!";
		 mySession.endUpload();

		 // Close FTP session
		 mySession.close();
	 }
	 catch(Poco::Net::NetException ex)
	 {
		 // Diplay log
		 textBoxLog->Text = gcnew String(ex.displayText().c_str());		 
	 }
 }

//
private: System::Void btnBrowseFile_Click(System::Object^  sender, System::EventArgs^  e) 
{
	
}

//
};


//
}

