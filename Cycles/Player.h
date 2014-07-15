//
//  Player.h
//  Cycles
//
//  Created by Yue Huang on 2014-07-13.
//  Copyright (c) 2014 Yue Huang. All rights reserved.
//

#ifndef __Cycles__Player__
#define __Cycles__Player__

#include "algebra.h"
#include "rect.h"
#include <SDL2/SDL_events.h>

class Player{
public:
    Rect hitbox;
    Player();
    ~Player();
    void render();
    void update(SDL_Event event);
};

#endif /* defined(__Cycles__Player__) */
