// Entrust.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Button.h"
#include "ActionListener.h"
#include "LoggerListener.h"

int main()
{
	Button okButton("OK");
	Button cancelButton("Cancel");

	LoggerListener logger("System");
	ActionListener action;

	okButton.addListener(&logger);
	okButton.addListener(&action);
	cancelButton.addListener(&logger);

	okButton.click();
	cancelButton.click();

}

