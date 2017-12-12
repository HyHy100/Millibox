#pragma once
#include"File.h"
#include<SFML\Graphics.hpp>
#include<memory>

class Workspace
{
	std::unique_ptr<File> file_;
	std::unique_ptr<sf::View> view_;
public:
	sf::View& getView();
	void setView(std::unique_ptr<sf::View>&& view);
	Workspace();
	~Workspace();
	void loadFile(std::shared_ptr<sf::Texture> file);
	File& getFile();
	void update();
	void render();
};
