#ifndef __LEVEL2_SCENE_H__
#define __LEVEL2_SCENE_H__

#include "cocos2d.h"
#include "tileset.h"
#include "cadre.h"
#include "Ourball.h"
class Level2Scene : public cocos2d::Layer
{
public:
    void update(float dt);
    void moveright(float dt);
    void moveleft(float dt);
    void movetop(float dt);
    void movebot(float dt);
    static cocos2d::Scene* createScene();
    virtual bool init();

   
   bool onContactBegin(cocos2d::PhysicsContact& contact);


    // implement the "static create()" method manually
    CREATE_FUNC(Level2Scene);

    
    cocos2d::Sprite* Square;
    cocos2d::Sprite* Obs1;
    std::vector<tile*> clouds;
    cocos2d::Sprite* cloud;
    cocos2d::Sprite* Obs2;
    cocos2d::Sprite* Obs3;
    cocos2d::Sprite* Obs4;
    cocos2d::Sprite* Obs0;
    cocos2d::Sprite* Obs01;
    Cadre* newcadre;
    Ourball* newball;
};

#endif // __LEVEL2_SCENE_H__

