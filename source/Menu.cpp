#include "stdafx.h"
#include "Menu.h"
#include "Application.h"
#include "ComponentManager.h"
#include "ImportWindow.h"
#include<imgui.h>

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::update() {
}

void Menu::render() {
	ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("Menu")) {
		if (ImGui::MenuItem("Open File", "Ctrl + O")) {
			ComponentManager::get().add<ImportWindow>("generic.png");
		}
		if (ImGui::MenuItem("Save", "Ctrl + S")) {
			ImGui::Text("FF");
		}
		ImGui::EndMenu();
	}

	ImGui::EndMainMenuBar();
}