#pragma once
#include<map>
#include<functional>
#include<array>
#include<SFML\Window.hpp>
#include<memory>
#include<initializer_list>
#include "Component.h"
#include"KeyboardManager.h"
#include"KeySet.h"

class KeyboardHandler
{
	std::vector<std::unique_ptr<KeySet>> _keyV;
	static KeyboardHandler* keyboardHandler;
public:
	static decltype(*keyboardHandler)& get();
	KeyboardHandler();
	~KeyboardHandler();
	virtual void update();
	virtual void render();
	void addKeySet(std::initializer_list<sf::Keyboard::Key>&& keys,
		std::function<void()>&& func,
		KeyStates&& eventType = std::move(KeyStates::Released));
};
