#pragma once
#include<string>
#include<memory>
#include<map>
#include"File.h"
#include"Animation.h"

class AnimationList {
	std::map<std::string, std::unique_ptr<Animation>> animationHash_;
public:
	decltype(animationHash_)& getAnimationHash();
	Animation& addAnimation(std::string name, File& file, size_t rangeBegin, size_t rangeEnd, int cellw, int cellh);
	Animation& getAnimation(std::string name);
};