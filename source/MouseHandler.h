#pragma once
#include<SFML\Window.hpp>

class MouseHandler
{
	static MouseHandler* mouseHandler_;
	sf::Vector2i prevMousePos_;
public:
	static decltype(*mouseHandler_)& get();
	void update();
	void render();
	MouseHandler();
	~MouseHandler();
};
