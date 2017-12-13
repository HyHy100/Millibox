#pragma once
#include"CollisionBox.h"
#include"HitBox.h"
#include"HurtBox.h"
#include"CollisionBox.h"
#include<SFML\Window.hpp>

class Boxes
{
	CollisionBoxList	collisionBoxes_;
	HitBoxList			hitBoxes_;
	HurtBoxList			hurtBoxes_;
	sf::IntRect			frameRect_;
public:
	Boxes();
	~Boxes();
	decltype(collisionBoxes_)&	getCollisionBoxes();
	decltype(hitBoxes_)&		getHitBoxes();
	decltype(hurtBoxes_)&		getHurtBoxes();
	decltype(frameRect_)&		getFrameRect();
};