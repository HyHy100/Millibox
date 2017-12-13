#pragma once
#include<vector>
#include<memory>
#include"PointGroup.h"

class CollisionBoxList {
	std::vector<std::shared_ptr<PointGroup>>	collisionboxes_;
public:
	decltype(collisionboxes_)&	getCollisionBoxes();
};