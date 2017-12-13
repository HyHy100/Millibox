#include "stdafx.h"
#include "OpenFileDialog.h"
#include<experimental\filesystem>
#include<imgui.h>
#include"sfml-imgui\imgui-SFML.h"
#include<algorithm>

OpenFileDialog::OpenFileDialog(std::string path)
{
	window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 400), "Open file");
	ImGui::SFML::Init(*window_);
}

OpenFileDialog::~OpenFileDialog()
{
}

void OpenFileDialog::update() {
}

void OpenFileDialog::render() {
	for (auto i = 0; i < files_.size(); ++i) {
		auto& file = files_[i];
		std::vector<sf::RectangleShape> shapes;
		//std::transform(files_.begin(), files_.end(), shapes.begin(), );
		//window_->draw();
	}
}