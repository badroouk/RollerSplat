#include "Level3Scene.h"
#include "GameOver.h"
#include "AudioEngine.h"
USING_NS_CC;
int count3 = 0;
bool ismoving3 = false;
bool ifApressed3 = false;
bool ifDpressed3 = false;
bool ifWpressed3 = false;
bool ifSpressed3 = false;
Scene* Level3Scene::createScene()
{
    
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

    auto layer = Level3Scene::create();
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
bool Level3Scene::init()
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
    auto lvl1 = Sprite::create("lvl3.png");
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
    auto shadow1 = Sprite::create("shadowcarre.png");
    auto shadow2 = Sprite::create("shadowcarre.png");
    auto shadow3 = Sprite::create("shadowcarre.png");
    auto shadow4 = Sprite::create("shadowcadre.png");
    auto shadow5 = Sprite::create("shadoow.png");
   Obs0 = Sprite::create("obstaclees.png");
   Obs0->setScale(0.98);
   auto Obs0body = PhysicsBody::createBox(Obs0->getContentSize(), PhysicsMaterial(0, 0, 0));
   Obs0body->setCollisionBitmask(2);
   Obs0body->setContactTestBitmask(true);
   Obs0body->setDynamic(false);
   Obs0->setPhysicsBody(Obs0body);
   Obs01 = Sprite::create("obstaclees.png");
   Obs01->setScale(0.98);

   auto Obs01body = PhysicsBody::createBox(Obs0->getContentSize(), PhysicsMaterial(0, 0, 0));
   Obs01body->setCollisionBitmask(2);
   Obs01body->setContactTestBitmask(true);
   Obs01body->setDynamic(false);
   Obs01->setPhysicsBody(Obs01body);

    Obs1 = Sprite::create("obstaclees.png");
    Obs1->setScale(0.98);
    auto Obs1body = PhysicsBody::createBox(Obs1->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs1body->setCollisionBitmask(2);
    Obs1body->setContactTestBitmask(true);
    Obs1body->setDynamic(false);
    Obs1->setPhysicsBody(Obs1body);
    Obs2 = Sprite::create("obstaclees.png");
    Obs2->setScale(0.98);
    auto Obs2body = PhysicsBody::createBox(Obs2->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs2body->setCollisionBitmask(2);
    Obs2body->setContactTestBitmask(true);
    Obs2body->setDynamic(false);
    Obs2->setPhysicsBody(Obs2body);
    Obs3 = Sprite::create("obstaclees.png");
    Obs3->setScale(0.98);
    auto Obs3body = PhysicsBody::createBox(Obs3->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs3body->setCollisionBitmask(2);
    Obs3body->setContactTestBitmask(true);
    Obs3body->setDynamic(false);
    Obs3->setPhysicsBody(Obs3body);
    Obs4 = Sprite::create("obstaclees.png");
    Obs4->setScale(0.98);

    auto Obs4body = PhysicsBody::createBox(Obs4->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs4body->setCollisionBitmask(2);
    Obs4body->setContactTestBitmask(true);
    Obs4body->setDynamic(false);
    Obs4->setPhysicsBody(Obs4body);
    Obs5 = Sprite::create("obstaclees.png");
    Obs5->setScale(0.98);

    auto Obs5body = PhysicsBody::createBox(Obs4->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs5body->setCollisionBitmask(2);
    Obs5body->setContactTestBitmask(true);
    Obs5body->setDynamic(false);
    Obs5->setPhysicsBody(Obs5body);

    Obs6 = Sprite::create("obstaclees.png");
    Obs6->setScale(0.98);
    auto Obs6body = PhysicsBody::createBox(Obs4->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs6body->setCollisionBitmask(2);
    Obs6body->setContactTestBitmask(true);
    Obs6body->setDynamic(false);
    Obs6->setPhysicsBody(Obs6body);

    Obs7 = Sprite::create("obstaclees.png");
    Obs7->setScale(0.98);
    auto Obs7body = PhysicsBody::createBox(Obs7->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs7body->setCollisionBitmask(2);
    Obs7body->setContactTestBitmask(true);
    Obs7body->setDynamic(false);
    Obs7->setPhysicsBody(Obs7body);
 
    for (auto i = 0; i < clouds.size(); i++)
    {  
        shadow1->setPosition(clouds[47]->getPosition());
        shadow2->setPosition(clouds[29]->getPosition());
        shadow3->setPosition(clouds[30]->getPosition());
        shadow4->setPosition(clouds[26]->getPosition());
        shadow5->setPosition(241.160004, 101.448784);
        CCLOG("%f %f", clouds[7]->getPosition().x, clouds[7]->getPosition().y);
        Obs1->setPosition(clouds[7]->getPosition());
        Obs0->setPosition(clouds[8]->getPosition());
        Obs01->setPosition(clouds[9]->getPosition());
        Obs2->setPosition(clouds[10]->getPosition());
        Obs3->setPosition(clouds[47]->getPosition());
        Obs4->setPosition(clouds[29]->getPosition());
        Obs5->setPosition(clouds[30]->getPosition());
        Obs6->setPosition(clouds[26]->getPosition());
        Obs7->setPosition(clouds[27]->getPosition());
    }
    this->addChild(Obs1, 1);
    this->addChild(Obs2, 1);
    this->addChild(Obs3, 1);
    this->addChild(Obs4, 1);
    this->addChild(Obs0, 1);
    this->addChild(Obs01, 1);
    this->addChild(Obs5, 1);
    this->addChild(Obs6, 1);
    this->addChild(Obs7, 1);
   this->addChild(shadow1, 3);
    this->addChild(shadow2, 3);
    this->addChild(shadow3, 2);
    this ->addChild(shadow4, 3);
    this->addChild(shadow5, 3);
    newball = new Ourball(this);
    newcadre = new Cadre(this);
   
    this->scheduleUpdate();
    auto eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (ismoving3 == false)
        {


            switch (keyCode) {
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case EventKeyboard::KeyCode::KEY_A:
                if (ifApressed3 == false)
                {
                    this->schedule(SEL_SCHEDULE(&Level3Scene::moveleft), 0.01);
                   // event->getCurrentTarget()->getPhysicsBody()->setVelocity(Vec2(-300, 0));
                    ismoving3 = true;
                    ifDpressed3 = false;
                    ifApressed3 = true;
                    ifWpressed3 = false;
                    ifSpressed3 = false;
                    cocos2d::AudioEngine::preload("audio/rolling.mp3");
                    cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
                }
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
                if (ifDpressed3 == false)
                {

                    this->schedule(SEL_SCHEDULE(&Level3Scene::moveright), 0.01);
                   // event->getCurrentTarget()->getPhysicsBody()->setVelocity(Vec2(300, 0));
                    ismoving3 = true;
                    ifDpressed3 = true;
                    ifApressed3 = false;
                    ifWpressed3 = false;
                    ifSpressed3 = false;
                    cocos2d::AudioEngine::preload("audio/rolling.mp3");
                    cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
                }
                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
                if (ifWpressed3 == false)
                {

                    this->schedule(SEL_SCHEDULE(&Level3Scene::movetop), 0.01);
                   // event->getCurrentTarget()->getPhysicsBody()->setVelocity(Vec2(0, 300));
                    ismoving3 = true;
                    ifDpressed3 = false;
                    ifApressed3 = false;
                    ifWpressed3 = true;
                    ifSpressed3 = false;
                    cocos2d::AudioEngine::preload("audio/rolling.mp3");
                    cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
                }
                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:
                if (ifSpressed3 == false)
                {

                    this->schedule(SEL_SCHEDULE(&Level3Scene::movebot), 0.01);
                   // event->getCurrentTarget()->getPhysicsBody()->setVelocity(Vec2(0, -300));
                    ismoving3 = true;
                    ifDpressed3 = false;
                    ifApressed3 = false;
                    ifWpressed3 = false;
                    ifSpressed3 = true;
                    cocos2d::AudioEngine::preload("audio/rolling.mp3");
                    cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
                }
                break;

            }
        }


    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Level3Scene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
   return true;
}

void Level3Scene::moveright(float dt) {
    Vec2 ballpos = newball->getposition();
    newball->setposition(ballpos.x + 320 * dt, ballpos.y);
    newball->setposition2(ballpos.x, ballpos.y);
    newball->setposition3(ballpos.x, ballpos.y);
}
void Level3Scene::moveleft(float dt) {
    Vec2 ballpos = newball->getposition();
    newball->setposition(ballpos.x - 300 * dt, ballpos.y);
    newball->setposition2(ballpos.x, ballpos.y);
    newball->setposition3(ballpos.x, ballpos.y);
}
void Level3Scene::movebot(float dt) {
    Vec2 ballpos = newball->getposition();
    newball->setposition(ballpos.x, ballpos.y - 300 * dt);
    newball->setposition2(ballpos.x, ballpos.y);
    newball->setposition3(ballpos.x, ballpos.y);
}
void Level3Scene::movetop(float dt) {
    Vec2 ballpos = newball->getposition();
    newball->setposition(ballpos.x, ballpos.y + 300 * dt);
    newball->setposition2(ballpos.x, ballpos.y);
    newball->setposition3(ballpos.x, ballpos.y);
}


bool Level3Scene::onContactBegin(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();

    // check if the bodies have collided
    if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
    {
        Vec2 x = newball->getposition();
        Vec2 y = newball->getposition2();
        if (ifDpressed3 == true)
        {
            this->unschedule(SEL_SCHEDULE(&Level3Scene::moveright));
            newball->setposition(b->getPosition().x - 23, x.y);
            newball->setposition2(b->getPosition().x - 23, y.y);
            auto splach = ParticleFireworks::create();
            splach->setPosition(newball->getposition().x + 10, newball->getposition().y);
            splach->setStartColor({ 255, 165, 1,255 });
            splach->setEndColor({ 255, 165, 1,0 });
            splach->setScale(0.3);
            splach->setDuration(0.07);
            splach->setStartSizeVar(40);
            splach->setAngle(180);
            this->addChild(splach, 2);
        }
        else if (ifApressed3 == true)
        {
            this->unschedule(SEL_SCHEDULE(&Level3Scene::moveleft));
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
        else if (ifSpressed3 == true)
        {
            this->unschedule(SEL_SCHEDULE(&Level3Scene::movebot));
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
        else if (ifWpressed3 == true)
        {
            this->unschedule(SEL_SCHEDULE(&Level3Scene::movetop));
            newball->setposition(x.x, b->getPosition().y - 23);
            newball->setposition2(y.x, b->getPosition().y - 23);
            auto splach = ParticleFireworks::create();
            splach->setPosition(newball->getposition().x , newball->getposition().y +10);
            splach->setStartColor({ 255, 165, 1,255 });
            splach->setEndColor({ 255, 165, 1,0 });
            splach->setScale(0.3);
            splach->setDuration(0.07);
            splach->setStartSizeVar(40);
            splach->setAngle(-90);
            this->addChild(splach, 2);
        }

        ismoving3 = false;
        cocos2d::AudioEngine::stopAll();
        cocos2d::AudioEngine::preload("audio/impact.mp3");
        cocos2d::AudioEngine::play2d("audio/impact.mp3");
    }

    return true;
}

void Level3Scene::update(float td) {
    for (auto sprite : clouds) {
        Rect rect1 = newball->getrect();
        Rect rect2 = sprite->getBoundingBox();
        Rect rect3 = Obs0->getBoundingBox();
        Rect rect4 = Obs1->getBoundingBox();
        Rect rect5 = Obs2->getBoundingBox();
        Rect rect6 = Obs3->getBoundingBox();
        Rect rect7 = Obs4->getBoundingBox();
        Rect rect8 = Obs5->getBoundingBox();
        Rect rect9 = Obs6->getBoundingBox();
        Rect rect10 = Obs7->getBoundingBox();
        Rect rect11 = Obs01->getBoundingBox();
        if (rect3.intersectsRect(rect2) )
        {
            sprite->setColor(Color3B(255, 165, 0));
        }
        if ( rect4.intersectsRect(rect2) )
        {
            sprite->setColor(Color3B(255, 165, 0));
        }
        if (rect5.intersectsRect(rect2) )
        {
            sprite->setColor(Color3B(255, 165, 0));
        }
        if (rect6.intersectsRect(rect2) )
        {
            sprite->setColor(Color3B(255, 165, 0));
        }
        if (rect7.intersectsRect(rect2) )
        {
            sprite->setColor(Color3B(255, 165, 0));
        }
        if ( rect8.intersectsRect(rect2))
        {
            sprite->setColor(Color3B(255, 165, 0));
        }
        if (rect9.intersectsRect(rect2))
        {
            sprite->setColor(Color3B(255, 165, 0));
        }
        if ( rect10.intersectsRect(rect2) )
        {
            sprite->setColor(Color3B(255, 165, 0));
        }
        if (rect11.intersectsRect(rect2))
        {
            sprite->setColor(Color3B(255, 165, 0));
        }
        if (rect1.intersectsRect(rect2) && sprite->iscolored == false && sprite->getColor()!= Color3B(255, 165, 0))
        {
            sprite->setColor(Color3B(255, 165, 0));
            count3++;
            sprite->iscolored = true;
            CCLOG("%d", count3);
        }
        if (count3 ==39  && ismoving3 == false) {
            auto scene4 = GameOver::createScene();
            Director::getInstance()->replaceScene(TransitionFade::create(0.8, scene4));
            this->unscheduleUpdate();
            
        }
    }

}
