// Memo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Editor.h"
#include "History.h"

int main()
{
	Editor editor;
	History history;


	editor.setContent("这是第1句话。");
	editor.setContent("这是第2句话。");
	editor.Show();

	history.push(editor.Save());
	editor.setContent("这是第3句话。");
	editor.Show();

	editor.Restor(history.pop());
	editor.Show();

	return 0;
}

