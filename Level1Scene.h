

#ifndef __Level1Scene_SCENE_H__
#define __Level1Scene_SCENE_H__
 
#include "cocos2d.h"
#include "tileset.h"
#include "Ourball.h"
#include "cadre.h"
class Level1Scene : public cocos2d::Layer
{

   
public:
    
    void update(float dt);
    void moveright(float dt);
    void moveleft(float dt);
    void movetop(float dt);
    void movebot(float dt);
    static cocos2d::Scene* createScene();
    virtual bool init();
    bool ifApressed = false;
    bool ifDpressed = false;
    bool ismoving = false;
    bool ifWpressed = false;
    bool ifSpressed = false;
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(Level1Scene);

    cocos2d::Sprite* Square;
    cocos2d::Sprite* Obs1;
    std::vector<tile*> clouds;
    cocos2d::Sprite* cloud;
    cocos2d::Sprite* Obs2;
    cocos2d::Sprite* Obs3;
    cocos2d::Sprite* Obs4;
    Ourball* kora;
    Cadre* newcadre;
};

#endif // __Level1Scene_SCENE_H__
