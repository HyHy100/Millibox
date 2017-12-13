#include"Animation.h"

AnimationID animationGetID() {
	static AnimationID id = 0;
	return id++;
}

Animation::Animation() {
	id_ = animationGetID();
}

Animation::~Animation() {
}

void Animation::update() {
}

void Animation::render() {
}

void Animation::setFrame(Frame& frame) {
	currentFrame_ = &frame;
}

Frame& Animation::addFrame() {
	frames_.emplace_back(std::make_unique<Frame>());
	return *frames_.back();
}

decltype(*Animation::currentFrame_)& Animation::getFrame() {
	return *currentFrame_;
}

decltype(Animation::frames_)& Animation::getFrameList() {
	return frames_;
}