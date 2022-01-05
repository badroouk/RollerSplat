
#include "Level1Scene.h" 
#include "Level2Scene.h"
#include <AudioEngine.h>

USING_NS_CC;
// create global variables to use later on.
int count=0;

//create our scene.
Scene* Level1Scene::createScene()
{
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

    auto layer = Level1Scene::create();
    scene->addChild(layer);
    return scene;
}


// we initialize our instance in init function.
bool Level1Scene::init()
{
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }  
   
   //------------------------------------------------------------create backgroud color-------------------------------------------------
    LayerColor* _bgColor = LayerColor::create(Color4B(206, 248, 252, 255));
    this->addChild(_bgColor, -10);
   
   //---------------------------------------------create variables for positioning our instance-------------------------------------------------------
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //---------------------adding lvl 1 image------------------------------------
    auto lvl1 = Sprite::create("lvl1.png");
    lvl1->setPosition(Vec2(2.84 * visibleSize.width /3, visibleSize.height/1.05));
    lvl1->setScale(0.5);
    this->addChild(lvl1, -2);
    //-------------------------------------------------create an edge box for our game------------------------------------------------------
    auto edgebody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    edgeNode->setPhysicsBody(edgebody);
    this->addChild(edgeNode);
    
    //--------------------------------------------- for loop to create tileset where the ball gonna move--------------------------------
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 6; j++)
    {
           auto _sprite = tile::tileinit();
        _sprite->setPosition(Vec2(2.84 * visibleSize.width / 4 + j * 23.4, visibleSize.height / 4.1 + i * 23.4));
        this->addChild(_sprite,1); 
        clouds.push_back(_sprite);
    }
}
    //-----------------------------------------------create obstacles for our level---------------------------------------------
    Obs1 = Sprite::create("square.png");
    Obs1->setScale(0.98);
    Obs2 = Sprite::create("shadow.png");
    //------------------------------------------------we add a physicall body to our obstacles---------------------------------
    auto Obs1body = PhysicsBody::createBox(Obs1->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs1body->setCollisionBitmask(2);
    Obs1body->setContactTestBitmask(true);
    Obs1body->setDynamic(false);
    Obs1->setPhysicsBody(Obs1body);
   
    //--------------------------------------------we set position of our sprites with the help of  and origin variables ----------------------------
    Obs1->setPosition(Point(( visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    Obs2->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    //-------------------------------------------we add our sprites to our layer --------------------------------------
    this->addChild(Obs1, 1);
    this->addChild(Obs2, 2);
    //------------------------------------------add a Frame and all from the cadre and ourball class--------------------------------------------------
    newcadre = new Cadre(this);
    kora = new Ourball(this);
    //-----------------------------------------set an scheduleupdate for our game ---------------------------------------------- 
    this->scheduleUpdate();

    //---------------------------------------create an event listener to read the interaction with the keyboard__________________________________________
    auto eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (ismoving==false)
        {
        switch (keyCode) {
        //case wich key is pressed
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            if (ifApressed==false)
            {
                //add a function to move our ball
                this->schedule(SEL_SCHEDULE(&Level1Scene::moveleft), 0.01);
            //a condition to see fif our ball moving
            ismoving = true;
            //we add soundon collision and on movion
            cocos2d::AudioEngine::preload("audio/rolling.mp3");
            cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
            //see wich key is pressed to not press it again
            ifApressed = true;
            ifDpressed = false;
            ifWpressed = false;
            ifSpressed = false;
            
            }
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            if (ifDpressed==false)
            {
             this->schedule(SEL_SCHEDULE(&Level1Scene::moveright), 0.01);
            ismoving = true;
            cocos2d::AudioEngine::preload("audio/rolling.mp3");
            cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
            ifDpressed = true;
            ifApressed = false;
            ifWpressed = false;
            ifSpressed = false;
           
            }
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            if (ifWpressed==false)
            {
                this->schedule(SEL_SCHEDULE(&Level1Scene::movetop), 0.01);
           // event->getCurrentTarget()->getPhysicsBody()->setVelocity(Vec2(0, 300));
            ismoving = true;
            cocos2d::AudioEngine::preload("audio/rolling.mp3");
            cocos2d::AudioEngine::play2d("audio/rolling.mp3", false, 0.3f);
            ifDpressed = false;
            ifApressed = false;
            ifWpressed = true;
            ifSpressed = false;
            
            }
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            if (ifSpressed==false)
            {
                this->schedule(SEL_SCHEDULE(&Level1Scene::movebot), 0.01);
            ismoving = true;
            cocos2d::AudioEngine::preload("audio/rolling.mp3");
            cocos2d::AudioEngine::play2d("audio/rolling.mp3",false,0.3f);
           
            ifDpressed = false;
            ifApressed = false;
            ifWpressed = false;
            ifSpressed = true;
            
            }
            break;
       
        }
    }


       
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
    //we create a contact listener to detect the collision of the ball with te walls and the obstacles
    auto contactListener = EventListenerPhysicsContact::create();
    //make a call back to the function everytime a contact happen
    contactListener->onContactBegin = CC_CALLBACK_1(Level1Scene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
   
    return true;
}
//functiions of mooving
void Level1Scene::moveright(float dt) {
    Vec2 ballpos = kora->getposition();
    kora->setposition(ballpos.x + 320 * dt, ballpos.y);
    kora->setposition2(ballpos.x, ballpos.y);
    kora->setposition3(ballpos.x, ballpos.y);
    }
void Level1Scene::moveleft(float dt) {
    Vec2 ballpos = kora->getposition();
    kora->setposition(ballpos.x - 300 * dt, ballpos.y);
    kora->setposition2(ballpos.x, ballpos.y);
    kora->setposition3(ballpos.x, ballpos.y);
}
void Level1Scene::movebot(float dt) {
    Vec2 ballpos = kora->getposition();
    kora->setposition(ballpos.x , ballpos.y - 300 * dt);
    kora->setposition2(ballpos.x, ballpos.y);
    kora->setposition3(ballpos.x, ballpos.y);
}
void Level1Scene::movetop(float dt) {
    Vec2 ballpos = kora->getposition();
    kora->setposition(ballpos.x , ballpos.y + 300 * dt);
    kora->setposition2(ballpos.x, ballpos.y);
    kora->setposition3(ballpos.x, ballpos.y);
}

//functions of contact
    bool Level1Scene::onContactBegin(cocos2d::PhysicsContact & contact)
    {
        PhysicsBody* a = contact.getShapeA()->getBody();
        PhysicsBody* b = contact.getShapeB()->getBody();

        // check if the bodies have collided
        if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
        {
            Vec2 x = kora->getposition();
            Vec2 y = kora->getposition2();
            if (ifDpressed == true)
            {
                this->unschedule(SEL_SCHEDULE(&Level1Scene::moveright));
                kora->setposition(b->getPosition().x - 23, x.y);
                kora->setposition2(b->getPosition().x - 23, y.y);
                auto splach = ParticleFireworks::create();
                splach->setPosition(kora->getposition().x + 10, kora->getposition().y);
                splach->setStartColor({ 255, 165, 1,255 });
                splach->setEndColor({ 255, 165, 1,0 });
                splach->setScale(0.3);
                splach->setDuration(0.07);
                splach->setStartSizeVar(40);
                splach->setAngle(180);
                this->addChild(splach, 2);
            }
            else if (ifApressed == true)
            {
                this->unschedule(SEL_SCHEDULE(&Level1Scene::moveleft));
                kora->setposition(b->getPosition().x + 23, x.y);
                kora->setposition2(b->getPosition().x + 23, y.y);
                auto splach = ParticleFireworks::create();
                splach->setPosition(kora->getposition().x - 10, kora->getposition().y);
                splach->setStartColor({ 255, 165, 1,255 });
                splach->setEndColor({ 255, 165, 1,0 });
                splach->setScale(0.3);
                splach->setDuration(0.07);
                splach->setStartSizeVar(40);
                splach->setAngle(360);
                this->addChild(splach, 2);
            }
            else if (ifSpressed == true)
            {
                this->unschedule(SEL_SCHEDULE(&Level1Scene::movebot));
                kora->setposition(x.x, b->getPosition().y + 23);
                kora->setposition2(y.x, b->getPosition().y + 23);
                auto splach = ParticleFireworks::create();
                splach->setPosition(kora->getposition().x , kora->getposition().y - 10);
                splach->setStartColor({ 255, 165, 1,255 });
                splach->setEndColor({ 255, 165, 1,0 });
                splach->setScale(0.3);
                splach->setDuration(0.07);
                splach->setStartSizeVar(40);
                this->addChild(splach, 2);
            }
            else if (ifWpressed == true)
            {
                this->unschedule(SEL_SCHEDULE(&Level1Scene::movetop));
                kora->setposition(x.x, b->getPosition().y - 23);
                kora->setposition2(y.x, b->getPosition().y - 23);
                auto splach = ParticleFireworks::create();
                splach->setPosition(kora->getposition().x , kora->getposition().y + 10);
                splach->setStartColor({ 255, 165, 1,255 });
                splach->setEndColor({ 255, 165, 1,0 });
                splach->setScale(0.3);
                splach->setDuration(0.07);
                splach->setStartSizeVar(40);
                splach->setAngle(-90);
                this->addChild(splach, 2);
            }

            ismoving = false;

            cocos2d::AudioEngine::stopAll();
            cocos2d::AudioEngine::preload("audio/impact.mp3");
            cocos2d::AudioEngine::play2d("audio/impact.mp3");
        }
        return true;
    }
    //function of coloring
    void Level1Scene::update(float dt) {
        for (auto sprite : clouds) {
            Rect rect1 = kora->getrect();
            Rect rect2 = sprite->getBoundingBox();

            if (rect1.intersectsRect(rect2) && sprite->iscolored == false)
            {
                sprite->setColor(Color3B(255, 165, 0));
                count++;
                sprite->iscolored = true;
              
            }
            //condition to moove to next level 
            if (count == 24 && ismoving == false) {
                auto scene2 = Level2Scene::createScene();
               Director::getInstance()->replaceScene(TransitionFade::create(0.2, scene2));
                this->unscheduleUpdate();
                
            }
        }
        
   }
   