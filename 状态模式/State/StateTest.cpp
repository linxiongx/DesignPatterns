#include "StateTest.h"

// Main 测试
int main2() 
{
	// 初始状态为空闲
	auto ct = std::make_unique<CTMachine>(std::make_unique<IdleState>());

	ct->requestScan(); // 输出：[空闲] 开始扫描流程... (内部切换为 Scanning)
	ct->requestScan(); // 输出：[扫描中] 已经在扫描了...
	ct->requestStop(); // 输出：[扫描中] 停止扫描... (内部切换为 Idle)
	ct->requestStop(); // 输出：[空闲] 机器已停止...

	return 0;
}