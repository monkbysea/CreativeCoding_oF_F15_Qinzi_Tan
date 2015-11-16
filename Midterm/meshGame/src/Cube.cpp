//  Cube.cpp
//  1112_prot8
//  Created by Qinzi Tan on 11/12/15.


#include "Cube.hpp"


//--------------------------------------------------------------
void Cube::setup(){
    ofSetCylinderResolution(20,20,20);
    w = ofGetWidth();
    h = ofGetHeight();
    
    r = 120;
    ang = ofRandom(TWO_PI);
    pos.y = r * sin(ang)+h/2;
    pos.x = r * cos(ang)+w/2;
    pos.z = ofRandom(-400,0);
   
//    pos.set(ofRandom(w/2-120,w/2+120),ofRandom(h/2-120,h/2+120),ofRandom(-200,0));
    color.set(162,224,247);
    angle = 0;
    state = int(ofRandom(1,3));
}

//--------------------------------------------------------------
void Cube::update(float _vel){
    vel = _vel;
    pos.z += vel;
    angle += ofRandom(0.3)*pi;
}

//--------------------------------------------------------------
void Cube::draw(){
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(pos);
//    spotlight.enable();
    
    if (state == 1) {
        ofRotateZ(angle);
        ofRotateX(angle);
        ofRotateY(angle);
        
        ofSetColor(color);
        ofDrawBox(0,0,0,8);
        
    } else if(state == 2){
        
        ofRotateZ(-angle);
        ofRotateX(-angle);
        ofRotateY(-angle);
        
        ofSetColor(color);
        ofDrawCylinder(0, 0, 0, 8,8);
    }
//    spotlight.disable();
    
    ofPopStyle();
    ofPopMatrix();
    
}

