#pragma once
#include"Component.h"
#include<vector>
#include<memory>

/*using ComponentID = size_t;

ComponentID getComponentID() {
	static ComponentID cid = 0;
	return ++cid;
}

template<typename T>
ComponentID getComponentID() {
	static ComponentID cid = getComponentID();
	return cid;
}*/

class ComponentManager
{
	static ComponentManager* componentManager_;
	std::vector<std::unique_ptr<Component>> components_;
public:
	static ComponentManager& get();
	ComponentManager();
	~ComponentManager();
	decltype(components_)& getComponents();
	void update();
	void render();
	template<typename T, typename... TArgs>
	T& add(TArgs... mArgs) {
		T* ptr = new T(mArgs...);
		auto uPtr = std::unique_ptr<T>{ ptr };
		components_.emplace_back(std::move(uPtr));
		return *ptr;
	}
	void removeByTag(Tags::Tags tag) {
		auto& components = getComponents();
		for (auto i = 0; i < components.size();) {
			if (components[i]->hasTag(tag)) {
				components.erase(components.begin() + i);
				continue;
			}
			++i;
		}
	}
};
