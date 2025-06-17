#include "Component.h"
#include <unordered_map>

//索引类，用于快速查找组件
class ComponentRegistry
{
public:
	void registerComponent(const string& strID, std::shared_ptr<Component> pComponent)
	{
		m_mapComponent[strID] = pComponent;
	}

	std::shared_ptr<Component> findComponent(const string& strID)
	{
		auto iter = m_mapComponent.find(strID);
		if (iter != m_mapComponent.end() && !iter->second.expired())
		{
			return iter->second.lock();
		}
		return nullptr;
	}

private:
	std::unordered_map<string, std::weak_ptr<Component>> m_mapComponent;
};