#include "stdafx.h"
#include "File.h"

File::File(std::shared_ptr<sf::Texture> file)
{
	texture_ = file;
	printf("File created\n");
}

File::~File()
{
}

sf::Texture& File::getTexture() { return *texture_; }
decltype(File::frames_)& File::getFrames() { return frames_; }

void File::update() {
	for (auto& i : frames_) {
		i->update();
	}
}

void File::render() {
	for (auto& i : frames_) {
		i->render();
	}
}

void File::setFrame(Frame& frame) {
	currentFrame_ = &frame;
}

Frame& File::getFrame() {
	return *currentFrame_;
}

void File::split(int cellw, int cellh) {
	auto tsize = getTexture().getSize();
	for (auto i = 0; i < tsize.y; i += cellh) {
		for (auto j = 0; j < tsize.x; j += cellw) {
			bool oobx = false;
			bool ooby = false;
			if (j + cellw > tsize.x) {
				oobx = true;
			}
			if (i + cellh > tsize.y) {
				ooby = true;
			}
			frames_.push_back(std::make_unique<Frame>());
			frames_.back()->setFrameRect({
				j,
				i,
				(oobx) ? (j + cellw - static_cast<int>(tsize.x)) : cellw,
				(ooby) ? (i + cellh - static_cast<int>(tsize.y)) : cellh
			});
		}
	}
	if (frames_.size() > 0 && !currentFrame_) {
		currentFrame_ = frames_.front().get();
	}
}