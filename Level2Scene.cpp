#include "Level2Scene.h"
#include "Level3Scene.h"
#include "AudioEngine.h"

USING_NS_CC;
int count2 = 0;
bool ismoving2 = false;
bool ifApressed2 = false;
bool ifDpressed2 = false;
bool ifWpressed2 = false;
bool ifSpressed2 = false;
Scene* Level2Scene::createScene()
{
    
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

    auto layer = Level2Scene::create();
    scene->addChild(layer);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Level2Scene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    LayerColor* _bgColor = LayerColor::create(Color4B(206, 248, 252, 255));
    this->addChild(_bgColor, -10);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //---------------------adding lvl 1 image------------------------------------
    auto lvl1 = Sprite::create("lvl2.png");
    lvl1->setPosition(Vec2(2.84 * visibleSize.width / 3, visibleSize.height / 1.05));
    lvl1->setScale(0.5);
    this->addChild(lvl1, -2);
    auto edgebody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    edgeNode->setPhysicsBody(edgebody);
    this->addChild(edgeNode);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++)
        {
            auto _sprite = tile::tileinit();
            _sprite->setPosition(Vec2(2.84 * visibleSize.width / 4 + j * 23.4, visibleSize.height / 4.1 + i * 23.4));
            this->addChild(_sprite, 1);
            clouds.push_back(_sprite);
        }
    }


 
    //create frame
    auto shadow1 = Sprite::create("shadowver.png");
    auto shadow2 = Sprite::create("shadow1.png");
    auto shadow3 = Sprite::create("shadowcarre.png");
    auto shadow4 = Sprite::create("shadowcarre.png");
   Obs0 = Sprite::create("obstaclees.png");
   auto Obs0body = PhysicsBody::createBox(Obs0->getContentSize(), PhysicsMaterial(0, 0, 0));
   Obs0body->setCollisionBitmask(2);
   Obs0body->setContactTestBitmask(true);
   Obs0body->setDynamic(false);
   Obs0->setPhysicsBody(Obs0body);

   Obs01 = Sprite::create("obstaclees.png");
   auto Obs01body = PhysicsBody::createBox(Obs0->getContentSize(), PhysicsMaterial(0, 0, 0));
   Obs01body->setCollisionBitmask(2);
   Obs01body->setContactTestBitmask(true);
   Obs01body->setDynamic(false);
   Obs01->setPhysicsBody(Obs01body);

    Obs1 = Sprite::create("obstaclees.png");
    auto Obs1body = PhysicsBody::createBox(Obs1->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs1body->setCollisionBitmask(2);
    Obs1body->setContactTestBitmask(true);
    Obs1body->setDynamic(false);
    Obs1->setPhysicsBody(Obs1body);

    Obs2 = Sprite::create("obstaclees.png");
    auto Obs2body = PhysicsBody::createBox(Obs2->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs2body->setCollisionBitmask(2);
    Obs2body->setContactTestBitmask(true);
    Obs2body->setDynamic(false);
    Obs2->setPhysicsBody(Obs2body);
    Obs3 = Sprite::create("obstaclees.png");
    auto Obs3body = PhysicsBody::createBox(Obs3->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs3body->setCollisionBitmask(2);
    Obs3body->setContactTestBitmask(true);
    Obs3body->setDynamic(false);
    Obs3->setPhysicsBody(Obs3body);
    Obs4 = Sprite::create("obs4.png");
    auto Obs4body = PhysicsBody::createBox(Obs4->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs4body->setCollisionBitmask(2);
    Obs4body->setContactTestBitmask(true);
    Obs4body->setDynamic(false);
    Obs4->setPhysicsBody(Obs4body);

    for (auto i = 0; i < clouds.size(); i++)
    {  
        shadow4->setPosition(clouds[7]->getPosition());
        shadow3->setPosition(clouds[44]->getPosition());
        shadow2->setPosition(clouds[28]->getPosition());
        shadow1->setPosition(clouds[4]->getPosition());
        Obs1->setPosition(clouds[7]->getPosition());
        Obs0->setPosition(clouds[3]->getPosition());
        Obs01->setPosition(clouds[5]->getPosition());
        Obs2->setPosition(clouds[4]->getPosition());
        Obs3->setPosition(clouds[44]->getPosition());
        Obs4->setPosition(clouds[28]->getPosition());

    }
    

    this->addChild(Obs1, 1);
    this->addChild(Obs2, 1);
    this->addChild(Obs3, 1);
    this->addChild(Obs4, 1);
    this->addChild(Obs0, 1);
    this->addChild(Obs01, 1);
    this->addChild(shadow1, 3);
    this->addChild(shadow2, 3);
    this->addChild(shadow3, 3);
    this->addChild(shadow4, 3);
    newcadre = new Cadre(this);
    newball = new Ourball(this);
    this->scheduleUpdate();
    auto eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (ismoving2 == false)
        {


            switch (keyCode) {
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case EventKeyboard::KeyCode::KEY_A:
                if (ifApressed2 == false)
                {
                    this->schedule(SEL_SCHEDULE(&Level2Scene::moveleft), 0.01);
                   // event->getCurrentTarget()->getPhysicsBody()->setVelocity(Vec2(-300, 0));
                    ismoving2 = true;
                    ifDpressed2 = false;
                    ifApressed2 = true;
                    ifWpressed2 = false;
                    ifSpressed2 = false;
                    cocos2d::AudioEngine::preload("audio/rolling.mp3");
                    cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
                }
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
                if (ifDpressed2 == false)
                {

                    this->schedule(SEL_SCHEDULE(&Level2Scene::moveright), 0.01);
                   // event->getCurrentTarget()->getPhysicsBody()->setVelocity(Vec2(300, 0));
                    ismoving2 = true;
                    ifDpressed2 = true;
                    ifApressed2 = false;
                    ifWpressed2 = false;
                    ifSpressed2 = false;
                    cocos2d::AudioEngine::preload("audio/rolling.mp3");
                    cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
                }
                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
                if (ifWpressed2 == false)
                {

                    this->schedule(SEL_SCHEDULE(&Level2Scene::movetop), 0.01);
                   // event->getCurrentTarget()->getPhysicsBody()->setVelocity(Vec2(0, 300));
                    ismoving2 = true;
                    ifDpressed2 = false;
                    ifApressed2 = false;
                    ifWpressed2 = true;
                    ifSpressed2 = false;
                    cocos2d::AudioEngine::preload("audio/rolling.mp3");
                    cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
                }
                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:
                if (ifSpressed2 == false)
                {

                    this->schedule(SEL_SCHEDULE(&Level2Scene::movebot), 0.01);
                   // event->getCurrentTarget()->getPhysicsBody()->setVelocity(Vec2(0, -300));
                    ismoving2 = true;
                    ifDpressed2 = false;
                    ifApressed2 = false;
                    ifWpressed2 = false;
                    ifSpressed2 = true;
                    cocos2d::AudioEngine::preload("audio/rolling.mp3");
                    cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
                }
                break;

            }
        }


    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Level2Scene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
   return true;
}

void Level2Scene::moveright(float dt) {
    Vec2 ballpos = newball->getposition();
    newball->setposition(ballpos.x + 320 * dt, ballpos.y);
    newball->setposition2(ballpos.x, ballpos.y);
    newball->setposition3(ballpos.x, ballpos.y);
}
void Level2Scene::moveleft(float dt) {
    Vec2 ballpos = newball->getposition();
    newball->setposition(ballpos.x - 300 * dt, ballpos.y);
    newball->setposition2(ballpos.x, ballpos.y);
    newball->setposition3(ballpos.x, ballpos.y);
}
void Level2Scene::movebot(float dt) {
    Vec2 ballpos = newball->getposition();
    newball->setposition(ballpos.x, ballpos.y - 300 * dt);
    newball->setposition2(ballpos.x, ballpos.y);
    newball->setposition3(ballpos.x, ballpos.y);
}
void Level2Scene::movetop(float dt) {
    Vec2 ballpos = newball->getposition();
    newball->setposition(ballpos.x, ballpos.y + 300 * dt);
    newball->setposition2(ballpos.x, ballpos.y);
    newball->setposition3(ballpos.x, ballpos.y);
}


bool Level2Scene::onContactBegin(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();

    // check if the bodies have collided
    if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
    {
        Vec2 x = newball->getposition();
        Vec2 y = newball->getposition2();
        if (ifDpressed2 == true)
        {
            this->unschedule(SEL_SCHEDULE(&Level2Scene::moveright));
            newball->setposition(b->getPosition().x - 23, x.y);
            newball->setposition2(b->getPosition().x - 23, y.y);
            auto splach = ParticleFireworks::create();
            splach->setPosition(newball->getposition().x+10, newball->getposition().y);
            splach->setStartColor({ 255, 165, 1,255 });
            splach->setEndColor({ 255, 165, 1,0 });
            splach->setScale(0.3);
            splach->setDuration(0.07);
            splach->setStartSizeVar(40);
            splach->setAngle(180);
            this->addChild(splach,2);
             
        }
        else if (ifApressed2 == true)
        {
            this->unschedule(SEL_SCHEDULE(&Level2Scene::moveleft));
            newball->setposition(b->getPosition().x + 23, x.y);
            newball->setposition2(b->getPosition().x + 23, y.y);
            auto splach = ParticleFireworks::create();
            splach->setPosition(newball->getposition().x - 10, newball->getposition().y);
            splach->setStartColor({ 255, 165, 1,255 });
            splach->setEndColor({ 255, 165, 1,0 });
            splach->setScale(0.3);
            splach->setDuration(0.07);
            splach->setStartSizeVar(40);
            splach->setAngle(360);
            this->addChild(splach, 2);
        }
        else if (ifSpressed2 == true)
        {
            this->unschedule(SEL_SCHEDULE(&Level2Scene::movebot));
            newball->setposition(x.x, b->getPosition().y + 23);
            newball->setposition2(y.x, b->getPosition().y + 23);
            auto splach = ParticleFireworks::create();
            splach->setPosition(newball->getposition().x , newball->getposition().y - 10);
            splach->setStartColor({ 255, 165, 1,255 });
            splach->setEndColor({ 255, 165, 1,0 });
            splach->setScale(0.3);
            splach->setDuration(0.07);
            splach->setStartSizeVar(40);
            this->addChild(splach, 2);
        }
        else if (ifWpressed2 == true)
        {
            this->unschedule(SEL_SCHEDULE(&Level2Scene::movetop));
            newball->setposition(x.x, b->getPosition().y - 23);
            newball->setposition2(y.x, b->getPosition().y - 23);
            auto splach = ParticleFireworks::create();
            splach->setPosition(newball->getposition().x , newball->getposition().y + 10);
            splach->setStartColor({ 255, 165, 1,255 });
            splach->setEndColor({ 255, 165, 1,0 });
            splach->setScale(0.3);
            splach->setDuration(0.07);
            splach->setStartSizeVar(40);
            splach->setAngle(-90);
            this->addChild(splach, 2);

        }

        ismoving2 = false;
      
        cocos2d::AudioEngine::stopAll();
        cocos2d::AudioEngine::preload("audio/impact.mp3");
        cocos2d::AudioEngine::play2d("audio/impact.mp3");
    }

    return true;
}

void Level2Scene::update(float td) {
    for (auto sprite : clouds) {
        Rect rect1 = newball->getrect();
        Rect rect2 = sprite->getBoundingBox();
        if (rect1.intersectsRect(rect2) && sprite->iscolored == false)
        {
            sprite->setColor(Color3B(255, 165, 0));
            count2++;
            sprite->iscolored = true;
        }
        if ((count2 >= 40 )&& ismoving2 == false) {

            auto scene3 = Level3Scene::createScene();
            Director::getInstance()->replaceScene(TransitionFade::create(0.3, scene3));
            this->unscheduleUpdate();
        }
    }

}
