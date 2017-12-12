#pragma once
#include<vector>

#include"Frame.h"

class File
{
	std::vector<std::unique_ptr<Frame>> frames_;
	std::shared_ptr<sf::Texture> texture_;
	Frame* currentFrame_;
public:
	File(std::shared_ptr<sf::Texture> file);
	~File();

	void update();
	void render();

	void setFrame(Frame& frame);
	Frame& getFrame();

	void split(int cellw, int cellh);

	decltype(frames_)& getFrames();
	sf::Texture& getTexture();
};