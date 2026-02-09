#pragma once

#include <iostream>
#include <memory>


// 子系统类：DVD播放器
class DVDPlayer {
public:
    void on() {
        std::cout << "DVD Player: 开机" << std::endl;
    }

    void play(const std::string& movie) {
        std::cout << "DVD Player: 播放电影 \"" << movie << "\"" << std::endl;
    }

    void stop() {
        std::cout << "DVD Player: 停止播放" << std::endl;
    }

    void off() {
        std::cout << "DVD Player: 关机" << std::endl;
    }
};

// 子系统类：投影仪
class Projector {
public:
    void on() {
        std::cout << "Projector: 开机" << std::endl;
    }

    void wideScreenMode() {
        std::cout << "Projector: 设置宽屏模式" << std::endl;
    }

    void off() {
        std::cout << "Projector: 关机" << std::endl;
    }
};

// 子系统类：音响系统
class SoundSystem {
public:
    void on() {
        std::cout << "Sound System: 开机" << std::endl;
    }

    void setVolume(int level) {
        std::cout << "Sound System: 设置音量为 " << level << std::endl;
    }

    void setSurroundSound() {
        std::cout << "Sound System: 设置环绕音效" << std::endl;
    }

    void off() {
        std::cout << "Sound System: 关机" << std::endl;
    }
};

// 子系统类：灯光系统
class Lights {
public:
    void dim(int level) {
        std::cout << "Lights: 调暗灯光至 " << level << "%" << std::endl;
    }

    void on() {
        std::cout << "Lights: 打开灯光" << std::endl;
    }
};
