#include "stdafx.h"
#include "PointGroup.h"

PointGroup::PointGroup()
{
}

PointGroup::~PointGroup()
{
}

decltype(PointGroup::points_)& PointGroup::getPoints() {
	return points_;
}

void PointGroup::addPoint(sf::Vector2f point) {
	points_.push_back(std::make_unique<Point>(point));
}

void PointGroup::update() {
}

void PointGroup::render() {
}