

#ifndef __BALL_H__
#define __BALL_H__

#include "cocos2d.h"
using namespace cocos2d;
//creating a class representing every image in the layer in other word every square in the layer surface and walls
class Ourball 
{
	
public:

	cocos2d::Vec2 getposition();
	void setposition(float x, float y);
	cocos2d::Vec2 getposition2();
	void setposition2(float x, float y);
	cocos2d::Rect getrect();
	cocos2d::Vec2 getposition3();
	void setposition3(float x, float y);
	Ourball(cocos2d::Layer* layer);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin; 
	//desctructor
	//this is where we initiate the sprite with a file path,
	cocos2d::Sprite* Kora;
	cocos2d::Sprite* ballShadow;
	cocos2d::ParticleMeteor* particle;
};
#endif