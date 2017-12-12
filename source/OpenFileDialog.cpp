#include "stdafx.h"
#include "OpenFileDialog.h"
#include<experimental\filesystem>
#include<imgui.h>
#include"sfml-imgui\imgui-SFML.h"

OpenFileDialog::OpenFileDialog(std::string path)
{
	window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 400), "Open file");
}

OpenFileDialog::~OpenFileDialog()
{
}

void OpenFileDialog::update() {
}

void OpenFileDialog::render() {
}