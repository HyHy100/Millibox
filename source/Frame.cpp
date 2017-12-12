#include "stdafx.h"
#include "Frame.h"

Frame::Frame()
{
}

Frame::~Frame()
{
}

decltype(Frame::collisionboxes_)&	Frame::getCollisionBoxes() { return collisionboxes_; }
decltype(Frame::hitboxes_)&			Frame::getHitboxes() { return hitboxes_; }
decltype(Frame::hurtboxes_)&		Frame::getHurtboxes() { return hurtboxes_; }
decltype(Frame::frameRect_)&		Frame::getFrameRect() { return frameRect_; }
void								Frame::setFrameRect(sf::IntRect rect) { frameRect_ = rect; }

void Frame::update() {
}

void Frame::render() {
}