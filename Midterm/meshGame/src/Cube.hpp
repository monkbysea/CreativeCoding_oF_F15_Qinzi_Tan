//  Cube.hpp
//  1112_prot8
//  Created by Qinzi Tan on 11/12/15.

#ifndef Cube_hpp
#define Cube_hpp

#include "ofMain.h"

#endif /* Cube_hpp */



class Cube : public ofBaseApp{
    
public:
    
    void setup();
    void update(float vel);
    void draw();
    
private:
    ofVec3f pos;
    float vel;
    float w,h;
    ofColor color;
    
    float angle;
    
    float state;
    
    ofLight spotlight;
    
    float r;
    float ang;
    
};
