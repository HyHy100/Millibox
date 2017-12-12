#pragma once

#include<vector>
#include<memory>
#include"Point.h"

class PointGroup
{
	std::vector<std::unique_ptr<Point>> points_;
public:
	decltype(points_)& getPoints();
	void addPoint(sf::Vector2f point);
	PointGroup();
	~PointGroup();
	virtual void update();
	virtual void render();
};
