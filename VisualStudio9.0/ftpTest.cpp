// ftpTest.cpp : main project file.

#include "stdafx.h"
#include "ftpTest.h"

using namespace ftpTest;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew frmFTPTest());
	return 0;
}
