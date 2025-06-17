#pragma once

#include "Component.h"
#include <list>
using std::list;
#include <memory>

class Composite : public Component, public std::enable_shared_from_this<Component>
{
public:
	Composite(string id)
		: Component(id)
	{

	}

	virtual ~Composite()
	{
		m_lstChildren.clear();
	}

	virtual void operation() const
	{
		std::cout << "ִ�����[" << this->getID() << "]����" << std::endl;
		for (auto iter = m_lstChildren.begin(); iter != m_lstChildren.end(); ++iter)
		{
			(*iter)->operation();
		}
	}

	virtual void add(std::shared_ptr<Component> p)
	{
		if(p != nullptr)
			m_lstChildren.push_back(p);
	}

	virtual void remove(std::shared_ptr<Component> p)
	{
		for (auto iter = m_lstChildren.begin(); iter != m_lstChildren.end(); ++iter)
		{
			if ((*iter)->getID() == p->getID())
			{
				m_lstChildren.erase(iter);
				break;
			}
		}
	}

	virtual std::shared_ptr<Component> find(string strID)
	{
		if (strID == m_strID)
		{
			//������
			//	int* p = new int(0);
			//std::shared_ptr<int> sp1(p);
			//std::shared_ptr<int> sp2(p);
			//std::cout << sp1.use_count() << std::endl; // 1
			//std::cout << sp2.use_count() << std::endl; // 1
			
			//return std::shared_ptr<Component>(this); //����������� ͨ�� this ָ�봴�� shared_ptr�������ִ�д���䣬�������shared_ptr, ÿ��shared_ptr���и��ԵĿ��ƿ飬ÿ�����ƿ�ָ��ͬһ��ַ(this)
			//return std::shared_ptr<Component>(this, [](Component*) {}); //�������shared_ptr, ÿ��shared_ptr���и��ԵĿ��ƿ�, ͨ���Զ���ɾ�����ﵽ���ͷ�ԭʼָ���Ŀ��

			try
			{
				//ʹ�� shared_from_this() ��ǰ���Ƕ�������Ѿ���һ�� std::shared_ptr �������������δ�� std::shared_ptr ����Ķ����ϵ��� shared_from_this()�����׳� std::bad_weak_ptr �쳣��
				return shared_from_this();
			}
			catch(const std::exception& e)
			{
				std::cout << "shared_from_this() �׳��쳣: " << e.what() << std::endl;
				return nullptr;
			}
	
		}	

		for (auto iter = m_lstChildren.begin(); iter != m_lstChildren.end(); ++iter)
		{
			if (auto pRet = (*iter)->find(strID);  pRet  != nullptr)
			{
				return pRet;
			}
		}

		return nullptr;
	}

private:
	list<std::shared_ptr<Component>> m_lstChildren;
};
