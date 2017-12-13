#include"KeySet.h"
#include"KeyboardManager.h"

void KeySet::update() {
	for (auto it = keys_.begin(); it < keys_.end() - 1; ++it) {
		if (KeyboardManager::get().getKeyState(*it) != KeyStates::Press && KeyboardManager::get().getKeyState(*it) != KeyStates::Pressed) {
			return;
		}
	}
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