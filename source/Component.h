#pragma once
#include<vector>
#include"tags.h"
#include<bitset>

class Component
{
	std::bitset<Tags::END> tags_;
public:
	Component();
	~Component();
	virtual void update() {}
	virtual void render() {}
	decltype(tags_)& getTags();
	void setTag(size_t tag);
	bool hasTag(size_t tag) const;
};
