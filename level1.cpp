/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h" 

USING_NS_CC;
int count=0;
bool ismoving = false;
bool ifApressed = false;
bool ifDpressed = false;
bool ifWpressed = false;
bool ifSpressed = false;
Scene* HelloWorld::createScene()
{
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

    auto layer = HelloWorld::create();
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
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }  
   
   
    LayerColor* _bgColor = LayerColor::create(Color4B(119, 136, 153, 255));
    this->addChild(_bgColor, -10);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto edgebody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    edgeNode->setPhysicsBody(edgebody);
    this->addChild(edgeNode);
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
  
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 6; j++)
    {
        cloud = Sprite::create("obstacle2.png");
        cloud->setPosition(Vec2(2.85*visibleSize.width/4 + j*22.8, visibleSize.height /4.1 + i*23.4));
        this->addChild(cloud, 1);
           clouds.push_back(cloud);
       
    }   
}
   
    Ball = Sprite::create("ball.png");
    auto static Ballbody = PhysicsBody::createCircle(Ball->getContentSize().width /2, PhysicsMaterial(0, 0, 0));
    Ballbody->setCollisionBitmask(1);
    Ballbody->setContactTestBitmask(true);
    Ball->setPhysicsBody(Ballbody);
    //create frame
    Frame1 = Sprite::create("formright.png");
    auto Frame1body = PhysicsBody::createBox(Frame1->getContentSize(), PhysicsMaterial(0, 0, 0));
    Frame1body->setCollisionBitmask(2);
    Frame1body->setContactTestBitmask(true);
    if (Frame1body != nullptr)
    {
        Frame1body->setDynamic(false);
        Frame1->setPhysicsBody(Frame1body);
    }

    Frame2 = Sprite::create("formright.png");
    auto Frame2body = PhysicsBody::createBox(Frame2->getContentSize(), PhysicsMaterial(0, 0, 0));
    Frame2body->setCollisionBitmask(2);
    Frame2body->setContactTestBitmask(true);
    if (Frame2body != nullptr)
    {
        Frame2body->setDynamic(false);
        Frame2->setPhysicsBody(Frame2body);
    }

    Frame3 = Sprite::create("formtop.png");
    auto Frame3body = PhysicsBody::createBox(Frame3->getContentSize(), PhysicsMaterial(0, 0, 0));
    Frame3body->setCollisionBitmask(2);
    Frame3body->setContactTestBitmask(true);
    if (Frame3body != nullptr)
    {
        Frame3body->setDynamic(false);
        Frame3->setPhysicsBody(Frame3body);
    }

    Frame4 = Sprite::create("formtop.png");
    auto Frame4body = PhysicsBody::createBox(Frame4->getContentSize(), PhysicsMaterial(0, 0, 0));
    Frame4body->setCollisionBitmask(2);
    Frame4body->setContactTestBitmask(true);
    if (Frame4body != nullptr)
    {
        Frame4body->setDynamic(false);
        Frame4->setPhysicsBody(Frame4body);
    }

    Obs1 = Sprite::create("obstacle2.png");
    auto Obs1body = PhysicsBody::createBox(Obs1->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs1body->setCollisionBitmask(2);
    Obs1body->setContactTestBitmask(true);
    Obs1body->setDynamic(false);
    Obs1->setPhysicsBody(Obs1body);

    Obs2 = Sprite::create("obstacle2.png");
    auto Obs2body = PhysicsBody::createBox(Obs2->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs2body->setCollisionBitmask(2);
    Obs2body->setContactTestBitmask(true);
    Obs2body->setDynamic(false);
    Obs2->setPhysicsBody(Obs2body);

    Obs3 = Sprite::create("obstacle2.png");
    auto Obs3body = PhysicsBody::createBox(Obs3->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs3body->setCollisionBitmask(2);
    Obs3body->setContactTestBitmask(true);
    Obs3body->setDynamic(false);
    Obs3->setPhysicsBody(Obs3body);

    Obs4 = Sprite::create("obstacle2.png");
    auto Obs4body = PhysicsBody::createBox(Obs4->getContentSize(), PhysicsMaterial(0, 0, 0));
    Obs4body->setCollisionBitmask(2);
    Obs4body->setContactTestBitmask(true);
    Obs4body->setDynamic(false);
    Obs4->setPhysicsBody(Obs4body);

    Frame1->setPosition(Point((visibleSize.width / 5.5) + origin.x, (visibleSize.height / 2) + origin.y));
    Frame2->setPosition(Point((3.28* visibleSize.width / 4) + origin.x, (visibleSize.height / 2) + origin.y));
    Frame3->setPosition(Point((visibleSize.width / 2) + origin.x, (3.32* visibleSize.height / 4) + origin.y));
    Frame4->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 5.9) + origin.y));
    for (auto i = 0; i < clouds.size(); i++)
    {
        auto static position = clouds[0]->getPosition();
        Ball->setPosition(position);
    }
    Obs1->setPosition(Point((3.1 * visibleSize.width / 4) + origin.x, (visibleSize.height / 2) + origin.y));
    Obs2->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height /2.5) + origin.y));
    Obs3->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 1.5) + origin.y));
   Obs4->setPosition(Point((visibleSize.width /4) + origin.x, (visibleSize.height / 2) + origin.y));

    this->addChild(Ball, 1);
    this->addChild(Frame1, 1);
    this->addChild(Frame2, 1);
    this->addChild(Frame3, 1);
    this->addChild(Frame4, 1);
    this->addChild(Obs1, 1);
    this->addChild(Obs2, 1);
    this->addChild(Obs3, 1);
    this->addChild(Obs4, 1);


    //Ball->setScale(0.16);
    //Frame1->setScale(0.5);
    //Frame2->setScale(0.5);
    //Frame3->setScale(0.5);
   // Frame4->setScale(0.5);
   // Obs2->setScale(0.5);
   // Obs1->setScale(0.5);

    this->scheduleUpdate();
    auto eventListener = EventListenerKeyboard::create();

    

    eventListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyPressed, this);
    eventListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::keyReleased, this);

    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
        if (ismoving==false)
        {

       
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            if (ifApressed==false)
            {
            
            Ballbody->setVelocity(Vec2(-300, 0));
            ismoving = true;
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
           

            Ballbody->setVelocity(Vec2(300, 0));
            ismoving = true;
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
          

            Ballbody->setVelocity(Vec2(0, 300));
            ismoving = true;
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
             

            Ballbody->setVelocity(Vec2(0, -300));
            ismoving = true;
            ifDpressed = false;
            ifApressed = false;
            ifWpressed = false;
            ifSpressed = true;
            
            }
            break;
       
        }
    }


    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, Ball);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
}

void HelloWorld::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
   
}
void HelloWorld::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    //  Rect rect1 = Ball->getBoundingBox();
      //Rect rect3 = Frame2->getBoundingBox();
      //if (rect1.intersectsRect(rect3))
      //{
       //   Vec2 batata = Ball->getPosition();
         // Vec2 batata2 = Frame2->getPosition();
         // CCLOG("7ADAAAHA");
          //Ball->stopAllActions();
      //}
   

   // for (auto i = 0; i < clouds.size(); i++)
     //   {
       //     for (auto j = i + 1; j < clouds.size(); j++) {

         //       if (clouds[i]->getColor() == Color3B(255, 0, 255) && clouds[i]->getColor() == clouds[j]->getColor())
          //     {
                   
           //         CCLOG("%d %d", i, j);
            //   }
           // }

//        }
    
}
    bool HelloWorld::onContactBegin(cocos2d::PhysicsContact & contact)
    {
        PhysicsBody* a = contact.getShapeA()->getBody();
        PhysicsBody* b = contact.getShapeB()->getBody();

        // check if the bodies have collided
        if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
        {
            Ball->getPhysicsBody()->setVelocity(Vec2(0,0));
            ismoving = false;

        }

        return true;
    }

    void HelloWorld::update(float td) {
        int static counter = 0;
        for (auto sprite : clouds) {
            Rect rect1 = Ball->getBoundingBox();
            Rect rect2 = sprite->getBoundingBox();
            if (rect1.intersectsRect(rect2))
            {
                counter++;
                if (sprite->getColor() == Color3B(255, 0, 0)) {
                    counter--;
                }
                sprite->setColor(Color3B(255, 0, 0));
            }
        }

       if(counter==48){
           log("next level");
       }
            
        
   }
   