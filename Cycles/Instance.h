//
//  Instance.h
//  Cycles
//
//  Created by Yue Huang on 2014-07-13.
//  Copyright (c) 2014 Yue Huang. All rights reserved.
//

#ifndef __Cycles__Instance__
#define __Cycles__Instance__

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>

#include "algebra.h"
#include "rect.h"
#include "Player.h"
#include "PathMap.h"

class Instance{
private:
    SDL_Window* gWindow;
    SDL_GLContext gContext;
    
    Instance();  // Private so that it can  not be called
public:
    Player p;
    PathMap path_map;
    
    static Instance& get();
    bool init_all();
    void destroy_all();
    void render();
    void update(SDL_Event event);
};
#endif /* defined(__Cycles__Instance__) */
