#include "stdafx.h"
#include "ImportWindow.h"
#include <imgui.h>
#include "sfml-imgui\imgui-SFML.h"
#include "tags.h"
#include "Application.h"
#include "ComponentManager.h"
#include "ShaderManager.h"

ImportWindow::ImportWindow(std::string path)
{
	setTag(Tags::CONTROLLER);
	setTag(Tags::WINDOW_IMAGE_IMPORT);
	content_ = std::make_shared<sf::Texture>();
	content_->loadFromFile(path);
	renderTexture_.create(content_->getSize().x, content_->getSize().y);
}

ImportWindow::~ImportWindow()
{
}

void ImportWindow::update() {
	bool open = true;
	ImGui::Begin("Import File", &open, ImVec2(800, 800));
	ImGui::Text("Frame size");
	ImGui::SameLine();
	ImGui::PushItemWidth(100);
	ImGui::Text("w: ");
	ImGui::SameLine();
	ImGui::InputInt("##framewidth", &frameSize_.x, 1, 1);
	ImGui::PopItemWidth();
	ImGui::SameLine();
	ImGui::PushItemWidth(100);
	ImGui::Text("h: ");
	ImGui::SameLine();
	ImGui::InputInt("##frameheight", &frameSize_.y);
	ImGui::PopItemWidth();
	sf::Sprite spr(renderTexture_.getTexture());
	spr.setPosition(sf::Vector2f(0, 0));
	ImGui::Image(spr);
	static int i = 0;
	i++;
	if (ImGui::Button("OK!")) {
		auto& workspace = Application::get().createWorkspace("Workspace " + std::to_string(i));
		Application::get().setWorkspace(workspace);
		Application::get().getWorkspace().loadFile(content_);
		workspace.getFile().split(frameSize_.x, frameSize_.y);
		ComponentManager::get().removeByTag(Tags::WINDOW_IMAGE_IMPORT);
	}
	ImGui::End();
}

void ImportWindow::render() {
	sf::Sprite spr(*content_);
	auto size = static_cast<sf::Vector2i>(spr.getTexture()->getSize());
	spr.setScale(1.0f, -1.0f);
	spr.setPosition(sf::Vector2f(0, size.y));
	static auto& shader = ShaderManager::get().find("shImport");
	shader.setUniform("texture", sf::Shader::CurrentTexture);
	shader.setUniform("frameSize", static_cast<sf::Vector2f>(frameSize_));
	renderTexture_.clear();
	renderTexture_.draw(spr, &shader);
}