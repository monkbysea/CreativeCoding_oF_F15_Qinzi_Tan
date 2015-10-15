//
//  Star.cpp
//  OF_Firework_1
//
//  Created by Qinzi Tan on 10/13/15.
//
//

#include "Star.hpp"

//--------------------------------------------------------------
void Star::setup(){
    pos.set(ofRandom(80,ofGetWidth()-80), ofRandom(30,ofGetHeight()-30),ofRandom(-30,-10));
//    starColor.set(ofRandom(10,20));
    vel.set(0, 0, ofRandom(0.5, 0.75));
    acc.set(0,0,ofRandom(-0.005, 0.005));
    radius = ofRandom(0.8, 1.15);
    sphere.setRadius(radius);
    spinX = ofRandom(0.60, 0.75);
    spinY = .4;
}

//--------------------------------------------------------------
void Star::update(){
    pos += vel;
//    vel += acc;
}

//--------------------------------------------------------------
void Star::draw(){

      starColor.set(ofRandom(100,120));
    
    ofPushStyle();
    ofSetColor(starColor);
    sphere.setPosition(pos);
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);
    sphere.draw();
    ofPopStyle();
    
    if (pos.z > 500) {
        pos.z = ofRandom(-30,-10);
    }
}

//--------------------------------------------------------------
void Star::keyPressed(int key){
    
}

//--------------------------------------------------------------
void Star::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Star::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Star::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Star::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Star::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Star::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Star::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Star::dragEvent(ofDragInfo dragInfo){
    
}
