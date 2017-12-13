#pragma once
#include<vector>
#include<memory>
#include<SFML\Graphics.hpp>
#include"Frame.h"

using AnimationID = size_t;

class Animation {
	std::vector<std::unique_ptr<Frame>> frames_;
	std::shared_ptr<sf::Texture> texture_;
	std::add_pointer<Frame>::type currentFrame_;
	AnimationID id_;
public:
	Animation();
	virtual ~Animation();
	void update();
	void render();
	decltype(frames_)& getFrameList();
	void setFrame(Frame& frame);
	Frame& addFrame();
	std::remove_pointer<decltype(currentFrame_)>::type& getFrame();
};