#pragma once

#include"Application.h"
#include"Component.h"
#include<imgui.h>

class FrameList : public Component
{
public:
	FrameList();
	~FrameList();
	virtual void update() override;
	virtual void render() override;
};
