#pragma once
#include "Component.h"
class Menu :
	public Component
{
public:
	Menu();
	~Menu();
	virtual void update() override;
	virtual void render() override;
};
