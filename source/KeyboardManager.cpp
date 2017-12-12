#include "KeyboardManager.h"

KeyboardManager* KeyboardManager::keyboardManager_ = nullptr;

KeyboardManager& KeyboardManager::get() {
	if (!keyboardManager_)
		keyboardManager_ = new KeyboardManager();
	return *keyboardManager_;
}

KeyboardManager::KeyboardManager()
{
	for (auto& i : _KeyM)
		i = KeyStates::Release;
}

void KeyboardManager::update()
{
	for (auto i = 0; i < _KeyM.size(); ++i)
	{
		auto& rK = _KeyM[i];
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i)))
		{
			switch (rK)
			{
			case KeyStates::Release:
				rK = KeyStates::Pressed;
				break;
			case KeyStates::Released:
				rK = KeyStates::Pressed;
				break;
			case KeyStates::Pressed:
				rK = KeyStates::Press;
				break;
			default:
				break;
			}
		}
		else
		{
			switch (rK)
			{
			case KeyStates::Pressed:
				rK = KeyStates::Released;
				break;
			case KeyStates::Press:
				rK = KeyStates::Released;
				break;
			case KeyStates::Released:
				rK = KeyStates::Release;
				break;
			default:
				break;
			}
		}
	}
}

KeyStates KeyboardManager::getKeyState(const sf::Keyboard::Key key) const {
	return _KeyM[key];
}