#include "stdafx.h"
#include "ShaderManager.h"

ShaderManager* ShaderManager::shaderManager_ = nullptr;

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

ShaderManager& ShaderManager::get()
{
	if (!shaderManager_) {
		shaderManager_ = new ShaderManager();
	}
	return *shaderManager_;
}

sf::Shader& ShaderManager::addShader(std::string name, std::string fVertexShader, std::string fFragShader)
{
	sf::Shader* shader = new sf::Shader();
	shader->loadFromFile(fVertexShader, fFragShader);
	shaderDict_.insert(shaderDict_.end(), { name, std::unique_ptr<sf::Shader>{shader} });
	return *shader;
}

void ShaderManager::remShader(std::string name)
{
	shaderDict_.erase(name);
}

sf::Shader& ShaderManager::find(std::string name) {
	auto it = shaderDict_.find(name);
	return *it->second;
}