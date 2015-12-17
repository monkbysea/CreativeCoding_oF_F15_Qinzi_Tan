//
//  Particle.hpp
//  flowFieldProt1
//
//  Created by Qinzi Tan on 11/29/15.
//


#ifndef Particle_hpp
#define Particle_hpp

#include "ofMain.h"

#endif /* Particle_hpp */


class particle
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    particle();
    
    void setInitialCondition(float px, float py, float vx, float vy);
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    
    
    void update();
    void draw(ofColor _starColor);
    
    void bounceOffWalls();
    
    bool  bFixed;
    
    float damping;
    ofColor starColor;
    
};

