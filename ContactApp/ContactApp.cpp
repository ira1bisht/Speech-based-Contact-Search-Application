// ContactApp.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include <stdio.h>
#include <Windows.h>

using namespace ContactApp;



[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Form1 ^obj=gcnew Form1();
	Application::Run(obj);
	return 0;
}
