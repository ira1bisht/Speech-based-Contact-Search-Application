#include "stdafx.h"
#include "Form1.h"

namespace  ContactApp{

void setLabel(Form1 ^ob)
{
	ob->label1->Text = L"Label changed for you";
	return;
}
}