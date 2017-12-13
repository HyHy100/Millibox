#pragma once
#include<string>
#include<map>
#include<memory>
#include<SFML\Graphics.hpp>
#include"WorkspaceManager.h"

class Application
{
	static Application* application_;
	std::unique_ptr<sf::RenderWindow> window;
	sf::Event wevent_;
	WorkspaceManager workspaceManager_;
public:
	decltype(workspaceManager_)& getWorkspaceManager();
	static Application& get();
	Application();
	~Application();
	sf::RenderWindow& getWindow();
	sf::Event& getEvent();
	void loadData();
	void run(size_t fps);
};
