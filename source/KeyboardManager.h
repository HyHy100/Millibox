#pragma once
#include<vector>
#include<SFML\Window.hpp>
#include<array>
#include"KeyStates.h"

class KeyboardManager
{
	static KeyboardManager* keyboardManager_;
	std::array<KeyStates, sf::Keyboard::KeyCount> _KeyM;
public:
	static decltype(*keyboardManager_)& get();
	KeyStates getKeyState(const sf::Keyboard::Key key) const;
	KeyboardManager();
	void update();
};