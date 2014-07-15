//
//  PathMap.h
//  Cycles
//
//  Created by Yue on 7/14/14.
//  Copyright (c) 2014 Yue Huang. All rights reserved.
//

#ifndef __Cycles__PathMap__
#define __Cycles__PathMap__

#include <SDL2/SDL_events.h>

struct Rect;

class PathMap{
public:
    bool **bit_map;
    Rect **rect_map;
    unsigned int column;
    unsigned int row;
    PathMap(unsigned int column, unsigned int row);
    ~PathMap();

    void render();
    void update(SDL_Event event);
};

#endif /* defined(__Cycles__PathMap__) */
