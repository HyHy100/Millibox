#include "stdafx.h"
#include "Boxes.h"

Boxes::Boxes()
{
}

Boxes::~Boxes()
{
}

decltype(Boxes::collisionBoxes_)& Boxes::getCollisionBoxes() {
	return collisionBoxes_;
}

decltype(Boxes::hitBoxes_)& Boxes::getHitBoxes() {
	return hitBoxes_;
}

decltype(Boxes::hurtBoxes_)& Boxes::getHurtBoxes() {
	return hurtBoxes_;
}

decltype(Boxes::frameRect_)& Boxes::getFrameRect() {
	return frameRect_;
}