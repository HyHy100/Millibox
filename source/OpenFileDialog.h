#pragma once
#include<string>
#include<SFML\Graphics.hpp>
#include<imgui.h>
#include<memory>
#include<vector>

class OpenDialogFile {
	sf::Texture icon;
	std::string fname;
public:
	OpenDialogFile(std::string fname) {
	}
	~OpenDialogFile() {
	}
	decltype(fname)& getFilename() {
		return fname;
	}
	decltype(icon)& getTexture() {
		return icon;
	}
};

class OpenFileDialog
{
	std::unique_ptr<sf::RenderWindow> window_;
	std::vector<OpenDialogFile> files_;
public:
	OpenFileDialog(std::string directory);
	~OpenFileDialog();
	void render();
	void update();
};
