#include "stdafx.h"
#include "Workspace.h"
#include "Application.h"
#include <SFML\Graphics.hpp>

Workspace::Workspace()
{
	view_ = std::make_unique<sf::View>();
}

Workspace::~Workspace()
{
}

void Workspace::update() {
	if (file_) {
		file_->update();
	}
}

void Workspace::render() {
	if (file_) {
		file_->render();
		auto& file = Application::get().getWorkspace().getFile();
		sf::Sprite frame = sf::Sprite(file.getTexture(), file.getFrame().getFrameRect());
		frame.setOrigin(this->getFile().getFrame().getFrameRect().width / 2,
			this->getFile().getFrame().getFrameRect().height / 2);
		frame.setPosition(Application::get().getWindow().getSize().x / 2, Application::get().getWindow().getSize().y / 2);
		Application::get().getWindow().draw(frame);
	}
}

sf::View& Workspace::getView() {
	return *view_;
}

void Workspace::setView(std::unique_ptr<sf::View>&& view) {
	view_ = std::move(view);
}

void Workspace::loadFile(std::shared_ptr<sf::Texture> file) {
	printf("file unique is in construction stage...\n");
	file_ = std::make_unique<File>(file);
	printf("did it!\n");
}

File& Workspace::getFile() {
	return *file_;
}