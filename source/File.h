#pragma once
#include<vector>
#include<memory>
#include<SFML\Graphics.hpp>

class File
{
	std::shared_ptr<sf::Texture> texture_;
public:
	File();
	~File();
	void load(std::shared_ptr<sf::Texture> texture);
	decltype(*texture_)& getTexture();
};
