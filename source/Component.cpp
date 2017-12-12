#include "stdafx.h"
#include "Component.h"

Component::Component()
{
}

Component::~Component()
{
}

decltype(Component::tags_)& Component::getTags() {
	return tags_;
}

void Component::setTag(size_t tag) {
	tags_[tag] = true;
}

bool Component::hasTag(size_t tag) const {
	return tags_[tag];
}