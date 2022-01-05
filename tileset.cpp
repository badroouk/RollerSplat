
#include "tileset.h"

USING_NS_CC;

tile::tile(void) {
	this->iscolored = false;
};

tile* tile::tileinit() {
	auto sprite = new tile();
	sprite->initWithFile("obstacle2.png");
	return sprite;
}