#pragma once
#include<vector>
#include<memory>
#include"PointGroup.h"

class HurtBoxList {
	std::vector<std::shared_ptr<PointGroup>>	hurtboxes_;
public:
	decltype(hurtboxes_)&		getHurtboxes();
};