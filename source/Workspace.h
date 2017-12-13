#pragma once
#include<SFML\Graphics.hpp>
#include<memory>
#include<map>
#include<algorithm>
#include<assert.h>
#include"File.h"
#include"Animation.h"
#include"AnimationList.h"
#include"Boxes.h"

class Workspace
{
	std::unique_ptr<File>				file_;
	sf::View							view_;
	AnimationList						animationList_;
	Animation*							currentAnimation_;
	Boxes								boxes_;
public:
	Workspace();
	~Workspace();
	void update();
	void render();
	void setCurrentAnimation(Animation& animation);
	decltype(*file_)&	getFile();
	decltype(view_)& getView();
	decltype(animationList_)& getAnimationList();
	decltype(*currentAnimation_)& getCurrentAnimation();
};
