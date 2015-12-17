//
//  Particle.cpp
//  flowFieldProt1
//
//  Created by Qinzi Tan on 11/29/15.
//
//

#include "Particle.hpp"


//------------------------------------------------------------
particle::particle(){
    setInitialCondition(0,0,0,0);
    damping = 0.03f;
    bFixed = false;
    }

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
    
}

//------------------------------------------------------------
void particle::resetForce(){
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}



//------------------------------------------------------------
void particle::update(){
    if (bFixed == false){
        vel = vel + frc;
        pos = pos + vel;
    }
}

//------------------------------------------------------------
void particle::draw(ofColor _starColor){
    
    starColor = _starColor;
    
    ofPushStyle();
    ofSetColor(starColor);
    ofDrawRectangle(pos.x, pos.y, 1.3,1.3);
    ofPopStyle();
}


//------------------------------------------------------------
void particle::bounceOffWalls(){
    
    bool bDampedOnCollision = true;
    bool bDidICollide = false;
    

    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    
    if (pos.x > maxx){
        pos.x = 0;
//        vel.x *= -1;
//        bDidICollide = true;
    } else if (pos.x < minx){
        pos.x = maxx;
//        vel.x *= -1;
//        bDidICollide = true;
    }
    
    if (pos.y > maxy){
        pos.y = 0;
//        vel.y *= -1;
//        bDidICollide = true;
    } else if (pos.y < miny){
        pos.y = maxy;
//        vel.y *= -1;
//        bDidICollide = true;
    }
    
    if (bDidICollide == true && bDampedOnCollision == true){
        vel *= 0.3;
    }
    
}
