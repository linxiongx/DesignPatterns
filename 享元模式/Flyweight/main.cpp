// Flyweight.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "TextEditor.h"

int main()
{
    TextEditor editor;

    // 使用相同的字体样式显示不同的字符
    editor.displayCharacter('A', 10, 10, "Arial", 12, "黑色");
    editor.displayCharacter('B', 20, 10, "Arial", 12, "黑色"); // 重用相同样式

    // 使用不同的字体样式
    editor.displayCharacter('C', 30, 10, "Times New Roman", 14, "红色");
    editor.displayCharacter('D', 40, 10, "Courier", 10, "蓝色");

    // 再次使用已有样式
    editor.displayCharacter('E', 50, 10, "Arial", 12, "黑色"); // 重用样式

    // 显示状态信息
    editor.showStats();
}

