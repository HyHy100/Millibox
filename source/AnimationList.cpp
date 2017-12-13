#include"AnimationList.h"
#include<assert.h>

decltype(AnimationList::animationHash_)& AnimationList::getAnimationHash() {
	return animationHash_;
}

Animation& AnimationList::addAnimation(std::string name, File& file, size_t rangeBegin, size_t rangeEnd, int cellw, int cellh) {
	printf("beginning f\n");
	sf::Texture& fTex = file.getTexture();
	auto tSize = fTex.getSize();
	auto& it = *animationHash_.insert(animationHash_.end(), {
		name,
		std::make_unique<Animation>()
	})->second;
	std::vector<sf::IntRect> frameRects;
	for (auto i = cellw*rangeBegin; i < cellw*rangeEnd; i += cellh) {
		for (auto j = cellh*rangeBegin; j < cellh*rangeEnd; j += cellw) {
			bool oobx = false;
			bool ooby = false;
			if (j + cellw > tSize.x) {
				oobx = true;
			}
			if (i + cellh > tSize.y) {
				ooby = true;
			}
			frameRects.push_back({
				static_cast<int>(j),
				static_cast<int>(i),
				(oobx) ? static_cast<int>(j + cellw - static_cast<int>(tSize.x)) : cellw,
				(ooby) ? static_cast<int>(i + cellh - static_cast<int>(tSize.y)) : cellh
			});
		}
	}
	assert(rangeBegin < rangeEnd);
	printf("beginning for\n");
	std::for_each(frameRects.begin() + rangeBegin, frameRects.begin() + rangeEnd, [&it](sf::IntRect& rec) {
		auto& frame = it.addFrame();
		frame.getBoxes().getFrameRect() = rec;
	});
	it.setFrame(*it.getFrameList()[0]);
	return it;
}

Animation& AnimationList::getAnimation(std::string name) {
	return *animationHash_[name];
}