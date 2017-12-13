#pragma once
#include<vector>
#include<memory>
#include"PointGroup.h"

class HitBoxList {
	std::vector<std::shared_ptr<PointGroup>>	hitboxes_;
public:
	decltype(hitboxes_)&		getHitboxes();
};