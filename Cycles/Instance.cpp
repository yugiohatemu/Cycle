//
//  Instance.cpp
//  Cycles
//
//  Created by Yue Huang on 2014-07-13.
//  Copyright (c) 2014 Yue Huang. All rights reserved.
//

#include "Instance.h"
#include <OpenGL/OpenGL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL.h>

Instance::Instance():path_map( 10,10 ){

}

Instance& Instance::get(){
    static Instance m_Instance;
    return m_Instance;
}

bool Instance::init_all(){
    
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return false;
	}else{
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
        
		gWindow = SDL_CreateWindow( "Room", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if( gWindow == NULL ){
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			return false;
		}else{
			//Create context
			gContext = SDL_GL_CreateContext( gWindow );
			if( gContext == NULL ){
				printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
				return false;
			}else{
				if( SDL_GL_SetSwapInterval( 1 ) < 0 ) printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
			}
		}
	}
    
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //enable alpha
    glEnable( GL_BLEND );
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,640,480,0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    return true;
}

void Instance::destroy_all(){
    SDL_DestroyWindow( gWindow );
	SDL_Quit();
}

void Instance::render(){
  
    glClear(GL_COLOR_BUFFER_BIT);
    path_map.render();
    p.render();
    SDL_GL_SwapWindow( gWindow );
}

void Instance::update(SDL_Event event){
    p.update(event);
}