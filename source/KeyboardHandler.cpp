#include "stdafx.h"
#include "KeyboardHandler.h"
#include "ImportWindow.h"
#include "ComponentManager.h"
#include "Application.h"
#include "KeySet.h"

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

	auto& workspaceManager = Application::get().getWorkspaceManager();
	addKeySet({
		sf::Keyboard::LControl,
		sf::Keyboard::Add
	}, [&workspaceManager]() {
		if (workspaceManager.getAllWorkspaces().size() > 0) {
			workspaceManager.getWorkspace().getView().zoom(0.25);
		}
	});

	addKeySet({
		sf::Keyboard::LControl,
		sf::Keyboard::Subtract
	}, [&workspaceManager]() {
		if (workspaceManager.getAllWorkspaces().size() > 0) {
			workspaceManager.getWorkspace().getView().zoom(-0.25);
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