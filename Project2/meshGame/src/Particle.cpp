//  Particle.cpp
//  meshGame3
//
//  Created by Qinzi Tan on 11/12/15.

#include "Particle.hpp"

//--------------------------------------------------------------
void Particle::setup(){
    pos.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),0);
    size = ofRandom(.6,1.3);
    
}

//--------------------------------------------------------------
void Particle::update(float _vel){
    
}

//--------------------------------------------------------------
void Particle::draw(){
    
    color.set(255,244,108,ofRandom(140,255));
    
    ofPushStyle();
    ofSetColor(color);
    ofDrawCircle(pos,size);
    
    ofPopStyle();
}

