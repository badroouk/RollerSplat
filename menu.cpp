#include "menu.h"
#include "Level1Scene.h"
#include "AudioEngine.h"


USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    LayerColor* _bgColor = LayerColor::create(Color4B(255, 255, 255, 255));
    this->addChild(_bgColor, -10);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto logo = Sprite::create("logo.png");
    logo->setPosition(Vec2(visibleSize.width-15, visibleSize.height/1.4 ));
    this->addChild(logo, -4);
    logo->setScale(0.5);
   
    auto playItem = MenuItemImage::create("button.png","pressed.png", CC_CALLBACK_1(MainMenu::GoToHelloWorldScene, this));
    auto menu = Menu::create(playItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 7);
    this->addChild(menu);

    return true;
}



void MainMenu::GoToHelloWorldScene(cocos2d::Ref* pSender)
{
    cocos2d::AudioEngine::preload("audio/Mouse.mp3");
    cocos2d::AudioEngine::play2d("audio/Mouse.mp3");
    auto scene = Level1Scene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5,scene));
}