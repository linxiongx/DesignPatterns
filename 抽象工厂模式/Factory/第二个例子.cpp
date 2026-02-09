#include <iostream>
using namespace std;

// 抽象产品：按钮
class Button {
public:
    virtual void paint() = 0;
    virtual ~Button() {}
};

// 抽象产品：文本框
class TextBox {
public:
    virtual void render() = 0;
    virtual ~TextBox() {}
};

// 抽象工厂：定义创建产品族的接口
class UIFactory {
public:
    virtual Button* createButton() = 0;
    virtual TextBox* createTextBox() = 0;
    virtual ~UIFactory() {}
};

// Windows 系列的具体产品
class WindowsButton : public Button {
public:
    void paint() override {
        cout << "渲染 Windows 风格按钮" << endl;
    }
};

class WindowsTextBox : public TextBox {
public:
    void render() override {
        cout << "渲染 Windows 风格文本框" << endl;
    }
};

// Mac 系列的具体产品
class MacButton : public Button {
public:
    void paint() override {
        cout << "渲染 Mac 风格按钮" << endl;
    }
};

class MacTextBox : public TextBox {
public:
    void render() override {
        cout << "渲染 Mac 风格文本框" << endl;
    }
};

// Windows 具体工厂
class WindowsFactory : public UIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }

    TextBox* createTextBox() override {
        return new WindowsTextBox();
    }
};

// Mac 具体工厂
class MacFactory : public UIFactory {
public:
    Button* createButton() override {
        return new MacButton();
    }

    TextBox* createTextBox() override {
        return new MacTextBox();
    }
};