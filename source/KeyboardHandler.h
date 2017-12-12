#pragma once
#include "Component.h"
#include<map>
#include<functional>
#include<array>
#include<SFML\Window.hpp>
#include<memory>
#include<initializer_list>
#include"KeyboardManager.h"

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
