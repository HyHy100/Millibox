#pragma once
#include<string>
#include<SFML\Graphics.hpp>
#include<imgui.h>
#include<memory>
#include<vector>

class OpenFileDialog
{
	std::unique_ptr<sf::RenderWindow> window_;
public:
	OpenFileDialog(std::string directory);
	~OpenFileDialog();
	void render();
	void update();
};
