#pragma once
#include"Component.h"
#include<SFML\Graphics.hpp>
#include<memory>

class ImportWindow : public Component
{
	sf::RenderTexture renderTexture_;
	std::shared_ptr<sf::Texture> content_;
	sf::Vector2i frameSize_;
public:
	ImportWindow(std::string path);
	~ImportWindow();
	virtual void update() override;
	virtual void render() override;
};