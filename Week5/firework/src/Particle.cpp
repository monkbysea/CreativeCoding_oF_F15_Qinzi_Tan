//
//  Particle.cpp
//  OF_Firework_1
//
//  Created by Qinzi Tan on 10/13/15.
//
//

#include "Particle.hpp"


//--------------------------------------------------------------
void Particle::setup(float _posX,
                     float _posY,
                     float _velX,
                     float _velY,
                     float _accX,
                     float _accY,
                     float _diameter,
                     ofColor _particleColor
//                     ofColor _burstAddColor
                     ){
    
    pos.x = _posX;
    pos.y = _posY;
    vel.x = _velX;
    vel.y = _velY;
    acc.x = _accX;
    acc.y = _accY;
    diameter = _diameter;
    particleColor = _particleColor;
//    burstAddColor = _burstAddColor;
    
    r = ofRandom(4,6);
    
    velState = int(ofRandom(1,3));
    
    velBurst.y = r * sin(ofRandom(360));
    if (velState == 1 ) {
        velBurst.x = sqrt(r*r - velBurst.y * velBurst.y);
    } else if (velState == 2 ) {
    velBurst.x = -sqrt(r*r - velBurst.y * velBurst.y);
    }
                      
    accBurst.y = 0.2;
    
}

//--------------------------------------------------------------
void Particle::update(){
    pos += vel;
    vel += acc;

}

//--------------------------------------------------------------
void Particle::draw(){
    
    ofPushStyle();
    ofSetColor(particleColor);
    ofEllipse(pos.x, pos.y, diameter, diameter);
    ofPopStyle();
    
    if(vel.y >= 0 ){
      goBurst();
    }
    
}


//--------------------------------------------------------------
void Particle::goBurst(){
   
    vel.set(0);
    acc.set(0);
//  particleColor = burstColor;
    
    
    pos += velBurst;
    velBurst += accBurst;
    if(velBurst.x > 0){
        accBurst.x = 0.05;
    } else if (velBurst.x < 0){
        accBurst.x = -0.05;
        }

}


//--------------------------------------------------------------
void Particle::keyPressed(int key){
    
}

//--------------------------------------------------------------
void Particle::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Particle::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Particle::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Particle::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Particle::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Particle::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Particle::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Particle::dragEvent(ofDragInfo dragInfo){
    
}
