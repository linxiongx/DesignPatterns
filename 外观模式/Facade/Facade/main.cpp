#include "Facade.h"

int main() 
{
    // 客户端只创建外观对象，不知道子系统的存在
    HomeTheaterFacade homeTheater;

    // 客户端只需要设置业务参数
    MovieConfig config;
    config.movieName = "星际穿越";
    config.volume = 7;
    config.lightLevel = 10;

    // 使用简化的接口
    homeTheater.watchMovie(config);

    std::cout << "正在观影中...\n" << std::endl;

    homeTheater.endMovie();

    return 0;
}
