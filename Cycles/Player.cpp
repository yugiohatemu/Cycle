//
//  Player.cpp
//  Cycles
//
//  Created by Yue Huang on 2014-07-13.
//  Copyright (c) 2014 Yue Huang. All rights reserved.
//

#include "Player.h"
#include <OpenGL/OpenGL.h>
#include <SDL2/SDL_opengl.h>

Player::Player(){
    hitbox.height = 50;
    hitbox.width = 50;
    hitbox.c.g = 0;
    hitbox.c.b = 0;
}

Player::~Player(){
    
}

void Player::render(){
    glPushMatrix();
    hitbox.render();
    glPopMatrix();
}

void Player::update(SDL_Event event){
    if (event.key.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                hitbox.top_left.y -= 3;
                break;
            case SDLK_DOWN:
                hitbox.top_left.y += 3;
                break;
            case SDLK_LEFT:
                hitbox.top_left.x -= 3;
                break;
            case SDLK_RIGHT:
                hitbox.top_left.x += 3;
                break;
            default:
                break;
        }
    }
}