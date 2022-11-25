#include "Form_ex1.h"


#include <iostream>
#include <string>
#include <Windows.h>
#include <msclr/marshal.h>
	

using namespace System;
using namespace System::Windows::Forms;
using namespace KPOLR2ex1;
using namespace std;
using namespace System::Runtime::InteropServices;



void main()
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Form_ex1());

}

