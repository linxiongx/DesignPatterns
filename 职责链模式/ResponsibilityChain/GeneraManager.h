#pragma once

#include "Manager.h"

class GeneraManager : public Manager
{
public:
	virtual void handler(double dMoney)
	{
		std::cout << "�ܾ���˵�������е���Ǯ�����С��Ҳ�����ң�׼�ˣ�" << std::endl;
	}
};