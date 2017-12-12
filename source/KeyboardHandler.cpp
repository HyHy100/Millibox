#include "stdafx.h"
#include "KeyboardHandler.h"
#include "ImportWindow.h"
#include "ComponentManager.h"
#include "Application.h"

void KeySet::update() {
	for (auto it = keys_.begin(); it < keys_.end() - 1; ++it) {
		if (KeyboardManager::get().getKeyState(*it) != KeyStates::Press && KeyboardManager::get().getKeyState(*it) != KeyStates::Pressed) {
			return;
		}
	}
	printf("all keys in press\n");
	if (KeyboardManager::get().getKeyState(*(keys_.end() - 1)) == KeyStates::Pressed) {
		callback_();
	}
}

KeySet::KeySet(std::initializer_list<sf::Keyboard::Key>&& keyset,
	std::function<void()>&& callback, KeyStates&& eType) {
	keys_.assign(keyset);
	callback_ = std::move(callback);
	eType_ = std::move(eType);
}

KeySet::~KeySet() {
}

KeyboardHandler* KeyboardHandler::keyboardHandler = nullptr;

KeyboardHandler::KeyboardHandler()
{
	addKeySet({
		sf::Keyboard::LControl,
		sf::Keyboard::O
	}, []() {
		printf("...");
		ComponentManager::get().add<ImportWindow>("generic2.png");
	});

	addKeySet({
		sf::Keyboard::LControl,
		sf::Keyboard::Add
	}, []() {
		if (Application::get().getAllWorkspaces().size() > 0) {
			Application::get().getWorkspace().getView().zoom(0.25);
		}
	});

	addKeySet({
		sf::Keyboard::LControl,
		sf::Keyboard::Subtract
	}, []() {
		if (Application::get().getAllWorkspaces().size() > 0) {
			Application::get().getWorkspace().getView().zoom(-0.25);
		}
	});
}

KeyboardHandler::~KeyboardHandler()
{
}

decltype(*KeyboardHandler::keyboardHandler)& KeyboardHandler::get() {
	if (!keyboardHandler)
		keyboardHandler = new KeyboardHandler();
	return *keyboardHandler;
}

void KeyboardHandler::update() {
	for (auto& i : _keyV) {
		i->update();
	}
}

void KeyboardHandler::render() {
}

void KeyboardHandler::addKeySet(std::initializer_list<sf::Keyboard::Key>&& keys, std::function<void()>&& func, KeyStates&& eType) {
	_keyV.push_back(std::make_unique<KeySet>(std::move(keys), std::move(func), std::move(eType)));
}