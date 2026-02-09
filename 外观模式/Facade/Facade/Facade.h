#pragma once

#include "SubSystem.h"
#include "SystemParams.h"

class HomeTheaterFacade {
private:
    // 子系统对象由外观类创建和管理（使用智能指针）
    std::unique_ptr<DVDPlayer> dvdPlayer;
    std::unique_ptr<Projector> projector;
    std::unique_ptr<SoundSystem> soundSystem;
    std::unique_ptr<Lights> lights;

public:
    // 构造函数：创建所有子系统对象
    HomeTheaterFacade()
        : dvdPlayer(std::make_unique<DVDPlayer>()),
        projector(std::make_unique<Projector>()),
        soundSystem(std::make_unique<SoundSystem>()),
        lights(std::make_unique<Lights>()) {
        std::cout << "家庭影院系统初始化完成\n" << std::endl;
    }

    // 简化接口：观看电影
    void watchMovie(const MovieConfig& config) {
        std::cout << "准备观看电影..." << std::endl;

        // 按特定顺序协调多个子系统
        lights->dim(config.lightLevel);
        projector->on();
        projector->wideScreenMode();
        soundSystem->on();
        soundSystem->setSurroundSound();
        soundSystem->setVolume(config.volume);
        dvdPlayer->on();
        dvdPlayer->play(config.movieName);

        std::cout << "开始享受电影吧！\n" << std::endl;
    }

    // 简化接口：结束观影
    void endMovie() {
        std::cout << "关闭影院系统..." << std::endl;

        // 按相反顺序关闭设备
        dvdPlayer->stop();
        dvdPlayer->off();
        soundSystem->off();
        projector->off();
        lights->on();

        std::cout << "影院系统已关闭\n" << std::endl;
    }
};

