
#include "Cadre.h"

USING_NS_CC;

Cadre::Cadre(cocos2d::Layer* layer) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
    auto Frame1 = Sprite::create("form.png");
    auto Frame1body = PhysicsBody::createBox(Frame1->getContentSize(), PhysicsMaterial(0, 0, 0));
    Frame1body->setCollisionBitmask(2);
    Frame1body->setContactTestBitmask(true);
    if (Frame1body != nullptr)
    {
        Frame1body->setDynamic(false);
        Frame1->setPhysicsBody(Frame1body);
    }

    auto Frame2 = Sprite::create("formright.png");
    auto Frame2body = PhysicsBody::createBox(Frame2->getContentSize(), PhysicsMaterial(0, 0, 0));
    Frame2body->setCollisionBitmask(2);
    Frame2body->setContactTestBitmask(true);
    if (Frame2body != nullptr)
    {
        Frame2body->setDynamic(false);
        Frame2->setPhysicsBody(Frame2body);
    }

    auto Frame3 = Sprite::create("formtop.png");
    auto Frame3body = PhysicsBody::createBox(Frame3->getContentSize(), PhysicsMaterial(0, 0, 0));
    Frame3body->setCollisionBitmask(2);
    Frame3body->setContactTestBitmask(true);
    if (Frame3body != nullptr)
    {
        Frame3body->setDynamic(false);
        Frame3->setPhysicsBody(Frame3body);
    }

    auto Frame4 = Sprite::create("formbot.png");
    auto Frame4body = PhysicsBody::createBox(Frame4->getContentSize(), PhysicsMaterial(0, 0, 0));
    Frame4body->setCollisionBitmask(2);
    Frame4body->setContactTestBitmask(true);
    if (Frame4body != nullptr)
    {
        Frame4body->setDynamic(false);
        Frame4->setPhysicsBody(Frame4body);
    }
    auto cadre = Sprite::create("cadre.png");

    cadre->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    Frame1->setPosition(Point((visibleSize.width / 5.58) + origin.x, (visibleSize.height / 2) + origin.y));
    Frame2->setPosition(Point((3.28 * visibleSize.width / 4) + origin.x, (visibleSize.height / 2) + origin.y));
    Frame3->setPosition(Point((visibleSize.width / 2) + origin.x, (3.32 * visibleSize.height / 4) + origin.y));
    Frame4->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 5.85) + origin.y));
    layer->addChild(Frame1, 1);
    layer->addChild(Frame2, 1);
    layer->addChild(Frame3, 1);
    layer->addChild(Frame4, 1);
    layer->addChild(cadre, 2);
};
