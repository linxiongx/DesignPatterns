#pragma once

#include "SoftwareFacade.h"
#include "HardwareFacade.h"

class SystemFacade
{
public:
	void bootUp()
	{
		cout << "======系统启动======" << endl;
		_hardware.initialize();
		_software.start();
		cout << "======启动完成======" << endl;
	}
private:
	HardwareFacade _hardware;
	SoftwareFacade _software;
};