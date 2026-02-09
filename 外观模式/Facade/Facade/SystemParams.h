#pragma once


#include <string>

struct MovieConfig {
    std::string movieName;      // 电影名称
    int volume;                 // 音量等级 (0-10)
    int lightLevel;             // 灯光亮度 (0-100)

    // 提供默认值
    MovieConfig()
        : movieName(""), volume(5), lightLevel(10)
    {

    }
};
