#pragma once
#include<string>
#include<map>
#include<memory>
#include<SFML\Graphics.hpp>

#include"Workspace.h"

class Application
{
	static Application* application_;
	std::map<std::string, std::unique_ptr<Workspace>> workspaces_;
	Workspace* currentWorkspace_;
	std::unique_ptr<sf::RenderWindow> window;
	sf::Event wevent_;
public:
	static Application& get();
	Application();
	~Application();
	Workspace& createWorkspace(std::string file);
	sf::RenderWindow& getWindow();
	sf::Event& getEvent();
	void setWorkspace(Workspace& workspace);
	Workspace& getWorkspace();
	decltype(workspaces_)& getAllWorkspaces();
	void loadData();
	void run(size_t fps);
};
