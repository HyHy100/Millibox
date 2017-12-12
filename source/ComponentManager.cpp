#include "stdafx.h"
#include "ComponentManager.h"

ComponentManager* ComponentManager::componentManager_ = nullptr;

ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}

ComponentManager& ComponentManager::get() {
	if (!componentManager_)
		componentManager_ = new ComponentManager();
	return *componentManager_;
}

decltype(ComponentManager::components_)& ComponentManager::getComponents() {
	return components_;
}

void ComponentManager::update() {
	for (auto& i : getComponents())
		i->update();
}

void ComponentManager::render() {
	for (auto& i : getComponents())
		i->render();
}