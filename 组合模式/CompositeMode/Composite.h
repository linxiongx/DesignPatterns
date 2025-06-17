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
		std::cout << "执行组件[" << this->getID() << "]操作" << std::endl;
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
			//举例：
			//	int* p = new int(0);
			//std::shared_ptr<int> sp1(p);
			//std::shared_ptr<int> sp2(p);
			//std::cout << sp1.use_count() << std::endl; // 1
			//std::cout << sp2.use_count() << std::endl; // 1
			
			//return std::shared_ptr<Component>(this); //会崩溃！！！ 通过 this 指针创建 shared_ptr，当多次执行此语句，创建多个shared_ptr, 每个shared_ptr都有各自的控制块，每个控制块指向同一地址(this)
			//return std::shared_ptr<Component>(this, [](Component*) {}); //创建多个shared_ptr, 每个shared_ptr都有各自的控制块, 通过自定义删除器达到不释放原始指针的目的

			try
			{
				//使用 shared_from_this() 的前提是对象必须已经被一个 std::shared_ptr 管理。如果尝试在未被 std::shared_ptr 管理的对象上调用 shared_from_this()，会抛出 std::bad_weak_ptr 异常。
				return shared_from_this();
			}
			catch(const std::exception& e)
			{
				std::cout << "shared_from_this() 抛出异常: " << e.what() << std::endl;
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
