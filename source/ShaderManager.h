#pragma once
#include<SFML\Graphics.hpp>
#include<string>
#include<map>
#include<memory>

class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();
private:
	std::map<std::string, std::unique_ptr<sf::Shader>>	shaderDict_;
	static ShaderManager* shaderManager_;
public:
	static ShaderManager& get();
	sf::Shader& addShader(std::string name, std::string fVertexShader, std::string fFragShader);
	void remShader(std::string name);
	sf::Shader& find(std::string name);
};
