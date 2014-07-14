//
//  main.cpp
//  Cycles
//
//  Created by Yue Huang on 2014-07-13.
//  Copyright (c) 2014 Yue Huang. All rights reserved.
//

#include "timer.h"
#include "Instance.h"

int main( int argc, char* args[] ){
    if(!Instance::get().init_all())return -1;
    
    bool quit = false;
    SDL_Event event;
    Timer timer(0.05);
    
    while( !quit ){
        while( SDL_PollEvent( &event ) ){
            if( event.type == SDL_QUIT )quit = true;
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) quit = true;
        }
        
        if (timer.is_timeup()) {
            Instance::get().update(event);
            Instance::get().render();
            timer.restart();
        }
    }
    
    Instance::get().destroy_all();
   	return 0;
}

