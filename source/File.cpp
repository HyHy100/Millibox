#include "stdafx.h"
#include "File.h"

File::File()
{
}

File::~File()
{
}

void File::load(std::shared_ptr<sf::Texture> texture) {
	texture_ = texture;
}

sf::Texture& File::getTexture() { return *texture_; }