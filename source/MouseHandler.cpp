#include "stdafx.h"
#include "MouseHandler.h"
#include "Application.h"
#include <SFML\Window.hpp>
#include <functional>

decltype(MouseHandler::mouseHandler_) MouseHandler::mouseHandler_ = nullptr;

decltype(*MouseHandler::mouseHandler_)& MouseHandler::get() {
	if (!mouseHandler_)
		mouseHandler_ = new MouseHandler();
	return *mouseHandler_;
}

MouseHandler::MouseHandler()
{
}

MouseHandler::~MouseHandler()
{
}

void MouseHandler::update() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle)) {
		auto& workspaces = Application::get().getAllWorkspaces();
		if (workspaces.size() > 0) {
			Application::get().getWorkspace().getView().move(
				std::move(sf::Vector2f(prevMousePos_.x - sf::Mouse::getPosition().x,
					prevMousePos_.y - sf::Mouse::getPosition().y))
			);
		}
	}
	prevMousePos_ = sf::Mouse::getPosition();
}

void MouseHandler::render() {
}