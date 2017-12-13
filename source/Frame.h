#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"PointGroup.h"
#include"Boxes.h"

class Frame
{
	std::vector<PointGroup>	hurtboxes_;
	Boxes boxes_;
	sf::IntRect frameRect_;
public:
	Frame();
	~Frame();
	decltype(boxes_)& getBoxes();
};
