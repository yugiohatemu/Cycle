//
//  PathMap.cpp
//  Cycles
//
//  Created by Yue on 7/14/14.
//  Copyright (c) 2014 Yue Huang. All rights reserved.
//

#include "PathMap.h"
#include <OpenGL/OpenGL.h>
#include <SDL2/SDL_opengl.h>
#include <algorithm>
#include "rect.h"

PathMap::PathMap(unsigned int column, unsigned int row):column(column),row(row){
    bit_map = new bool *[row];
    for (unsigned int i =0; i < row; i++) {
        bit_map[i] = new bool [column];
        std::fill(bit_map[i], bit_map[i] + column, false);
    }
    
    srand(time(NULL));
    unsigned int rand_count = column * row * 0.15;
    for (unsigned int i = 0; i < rand_count; i++) {
        unsigned int r = rand() % row;
        unsigned int c = rand() % column;
        bit_map[r][c] = true;
    }
    
    rect_map = new Rect *[row];
    for (unsigned int i = 0; i < row; i++) {
        rect_map[i] = new Rect[column];
        for (unsigned int j = 0; j < column; j++) {
            rect_map[i][j].top_left.x = j * 50;
            rect_map[i][j].top_left.y = i * 50;
            rect_map[i][j].width = 50;
            rect_map[i][j].height = 50;
            if (bit_map[i][j]) {
                rect_map[i][j].c = Color(0,0,0);
            }
        }
    }
}

PathMap::~PathMap(){
    for (unsigned int i =0; i < row; i++) {
        delete [] bit_map[i];
    }
    delete [] bit_map;
    
    for (unsigned int i =0; i < row; i++) {
        delete [] rect_map[i];
    }
    delete [] rect_map;
}

//Theoretically, the whole block can be cached...
//For efficiently, cna use 1-d array instead of two
void PathMap::render(){
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glVertex2f(0, 0); glVertex2f(640, 0);
    glVertex2f(640, 480); glVertex2f(0,480);
    glEnd();
    glPopMatrix();
    
    //Just render the block
    glPushMatrix();
    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < column; j++) {
             if(bit_map[i][j])rect_map[i][j].render();
        }
    }
    
    glPopMatrix();
}

void PathMap::update(SDL_Event event){
    
}