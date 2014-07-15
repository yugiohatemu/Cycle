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
#include "PathMap.h"

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
                if (y > 0 && !path_map->bit_map[y-1][x]) {
                    hitbox.top_left.y -= 50;
                }
                break;
            case SDLK_DOWN:
                if (y < path_map->row-1 && !path_map->bit_map[y+1][x]) {
                    hitbox.top_left.y += 50;
                }
                break;
            case SDLK_LEFT:
                if (x > 0 && !path_map->bit_map[y][x-1]) {
                    hitbox.top_left.x -= 50;
                }
                break;
            case SDLK_RIGHT:
                if (x < path_map->column-1 && !path_map->bit_map[y][x+1]) {
                    hitbox.top_left.x += 50;
                }
                break;
            default:
                break;
        }
    }
}