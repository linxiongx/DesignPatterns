#pragma once

#include "SoftwareFacade.h"
#include "HardwareFacade.h"

class SystemFacade
{
public:
	void bootUp()
	{
		cout << "======ϵͳ����======" << endl;
		_hardware.initialize();
		_software.start();
		cout << "======�������======" << endl;
	}
private:
	HardwareFacade _hardware;
	SoftwareFacade _software;
};