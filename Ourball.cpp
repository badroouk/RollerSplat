
#include "Ourball.h"

USING_NS_CC;

Ourball::Ourball(cocos2d::Layer* layer) {
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	Kora = Sprite::create("balll.png");
	Kora->setScale(0.96);
	Kora->setPosition(Point(181.759995 ,78.048782));
	auto  Ballbody = PhysicsBody::createCircle(Kora->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
	Ballbody->setCollisionBitmask(1);
	Ballbody->setContactTestBitmask(true);
	Kora->setPhysicsBody(Ballbody);
	ballShadow = Sprite::create("ballShadow.png");
	ballShadow->setScale(0.96);
	ballShadow->setPosition(Point(181.759995 ,78.048782));
	particle = ParticleMeteor::create();
	particle->setDuration(ParticleSystem::DURATION_INFINITY);
	particle->setEmitterMode(ParticleSystem::Mode::GRAVITY);
	particle->setPositionX(181.759995);
	particle->setPositionY(78.048782);
	particle->setGravity(Vec2(0, 0));
	particle->setScale(0.6);
	particle->setStartSize(50);
	particle->setEndSize(50);
	particle->setLife(0.09);
	particle->setTotalParticles(100);
	Color4F color = { 255, 165, 1,1 };
	particle->setStartColor(color);


	layer->addChild(particle, 1);
	layer->addChild(Kora,1);
	layer->addChild(ballShadow,1.5);
};

cocos2d::Vec2 Ourball::getposition() {
	return Kora->getPosition();
}

void  Ourball::setposition(float x,float y) {
	Kora->setPosition(Point(x, y));
}
cocos2d::Vec2 Ourball::getposition2() {
	return ballShadow->getPosition();
}

void  Ourball::setposition2(float x, float y) {
	ballShadow->setPosition(Point(x, y));
}
cocos2d::Rect Ourball::getrect() {
	return Kora->getBoundingBox();
}
cocos2d::Vec2 Ourball::getposition3() {
	return particle->getPosition();
}

void  Ourball::setposition3(float x, float y) {
	particle->setPosition(Point(x, y));
}