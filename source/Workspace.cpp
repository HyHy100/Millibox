#include "stdafx.h"
#include "Workspace.h"
#include "Application.h"
#include <SFML\Graphics.hpp>

Workspace::Workspace()
{
	file_ = std::make_unique<File>();
}

Workspace::~Workspace()
{
}

sf::View& Workspace::getView() {
	return view_;
}

decltype(*Workspace::file_)& Workspace::getFile() {
	return *file_;
}

void Workspace::setCurrentAnimation(Animation& animation) {
	currentAnimation_ = &animation;
}

void Workspace::update() {}

void Workspace::render() {
	auto& file = Application::get().getWorkspaceManager().getWorkspace().getFile();
	sf::Sprite frame = sf::Sprite(getFile().getTexture(), getCurrentAnimation().getFrame().getBoxes().getFrameRect());

	frame.setOrigin(getCurrentAnimation().getFrame().getBoxes().getFrameRect().width / 2,
		getCurrentAnimation().getFrame().getBoxes().getFrameRect().height / 2);

	frame.setPosition(Application::get().getWindow().getSize().x / 2, Application::get().getWindow().getSize().y / 2);
	Application::get().getWindow().draw(frame);
}

decltype(Workspace::animationList_)& Workspace::getAnimationList() {
	return animationList_;
}

decltype(*Workspace::currentAnimation_)& Workspace::getCurrentAnimation() {
	return *currentAnimation_;
}