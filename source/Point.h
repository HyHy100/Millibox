#pragma once
#include<SFML\Graphics.hpp>

class Point
{
	sf::Vector2f point_;
public:
	Point(sf::Vector2f point);
	~Point();
};
