#pragma once
#include<vector>
#include<functional>
#include<SFML\Window.hpp>
#include<initializer_list>
#include"KeyStates.h"

class KeySet {
	std::vector<sf::Keyboard::Key> keys_;
	std::function<void()> callback_;
	KeyStates eType_;
public:
	KeySet(std::initializer_list<sf::Keyboard::Key>&& keyset,
		std::function<void()>&& callback,
		KeyStates&& eType);
	~KeySet();
	void update();
};