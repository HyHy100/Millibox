#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"PointGroup.h"

class Frame
{
	std::vector<std::shared_ptr<PointGroup>>	collisionboxes_;
	std::vector<std::shared_ptr<PointGroup>>	hitboxes_;
	std::vector<std::shared_ptr<PointGroup>>	hurtboxes_;
	sf::IntRect frameRect_;
public:
	decltype(collisionboxes_)&	getCollisionBoxes();
	decltype(hitboxes_)&		getHitboxes();
	decltype(hurtboxes_)&		getHurtboxes();
	decltype(frameRect_)&		getFrameRect();
	void						setFrameRect(sf::IntRect rect);
	void update();
	void render();

	Frame();
	~Frame();
};
