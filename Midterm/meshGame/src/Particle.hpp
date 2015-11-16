//  Particle.hpp
//  meshGame3
//
//  Created by Qinzi Tan on 11/12/15.


#ifndef Particle_hpp
#define Particle_hpp

#include "ofMain.h"

#endif /* Particle_hpp */


class Particle : public ofBaseApp{
    
public:
    
    void setup();
    void update(float vel);
    void draw();
    
private:
    ofVec3f pos;
    ofColor color;
    float size;
};
