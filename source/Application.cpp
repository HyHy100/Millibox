#include "stdafx.h"
#include "Application.h"
#include "ShaderManager.h"
#include <imgui.h>
#include "ComponentManager.h"
#include "sfml-imgui\imgui-SFML.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"
#include "KeyboardManager.h"

Application* Application::application_ = nullptr;

decltype(Application::workspaceManager_)& Application::getWorkspaceManager() {
	return workspaceManager_;
}

Application& Application::get() {
	if (!application_)
		application_ = new Application();
	return *application_;
}

Application::Application()
{
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1280, 800), "Millibox DEV");
	ImGui::SFML::Init(*window);
}

Application::~Application()
{
}

sf::Event& Application::getEvent() {
	return wevent_;
}

void Application::loadData() {
	ShaderManager::get().addShader("shImport", "import.vert", "import.frag");
}

sf::RenderWindow& Application::getWindow() {
	return *window;
}

void Application::run(size_t fps) {
	loadData();
	sf::Clock deltaClock;
	bool quit = false;
	window->setVerticalSyncEnabled(true);
	while (!quit) {
		sf::Event& wevent = wevent_;
		wevent = sf::Event();
		getWindow().pollEvent(wevent);
		ImGui::SFML::ProcessEvent(wevent);
		ImGui::SFML::Update(getWindow(), deltaClock.restart());
		getWindow().clear(sf::Color(245, 245, 245, 255));
		auto& workspaces = getWorkspaceManager().getAllWorkspaces();
		ImGui::Begin("Workspaces");
		auto counter = 0u;
		if (workspaces.size() > 0) {
			getWindow().setView(getWorkspaceManager().getWorkspace().getView());
		}
		for (auto& i : workspaces) {
			ImGui::PushID(counter);
			if (ImGui::Button(i.first.c_str())) {
				getWorkspaceManager().setWorkspace(*i.second);
			}
			ImGui::PopID();
			ImGui::SameLine();
			++counter;
		}
		ImGui::End();
		printf("bcex\n");
		if (getWorkspaceManager().getAllWorkspaces().size() > 0) {
			getWorkspaceManager().getWorkspace().update();
			getWorkspaceManager().getWorkspace().render();
		}
		printf("bcex\n");
		KeyboardManager::get().update();
		MouseHandler::get().update();
		MouseHandler::get().render();
		KeyboardHandler::get().update();
		KeyboardHandler::get().render();
		ComponentManager::get().update();
		ComponentManager::get().render();
		ImGui::SFML::Render(getWindow());
		getWindow().display();
	}
	ImGui::SFML::Shutdown();
}