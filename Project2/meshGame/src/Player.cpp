//  Player.cpp
//  prot10
//  Created by Qinzi Tan on 11/1/15.


#include "Player.hpp"

//-----------------------

Player::Player(){
    attractPoints = NULL;
}

//------------------------------------------------------------------
void Player::setAttractPoints( vector <ofPoint> * attract ){
    attractPoints = attract;
}


//--------------------------------------------------------------
void Player::setup(){
    cX = ofGetWidth()/2;
    cY = ofGetHeight()/2;
    
    //player
    playerImg.load("player.png");
    pColor.set(70);
    pAngle = 1.5*pi;
    pR = 220;
    pRotateAng = 0;
    pRotateX = -30;
    
    pos.x = ofRandom(400,600);
    pos.y = ofRandom(ofGetHeight()-100,ofGetHeight()-70);
    
    
    vel.x = ofRandom(0, 0.1);
    vel.y = ofRandom(0, 0.1);
    
    
    frc   = ofPoint(0,0,0);
    
    scale = ofRandom(1.0, 1.5);
    drag  = ofRandom(0.95, 0.998);
}

//--------------------------------------------------------------
void Player::update(){
    //player
    pPos.x = pR * - cos(pAngle);
    pPos.y = pR * - sin(pAngle);
    //    pPos.z --;
    
    //follower
    ofPoint attractPt(pPos.x+17.5, pPos.y+42, pPos.z);
    
    frc = attractPt-pos;
    frc.normalize();
    vel *= drag;
    vel += frc * 0.6;
    pos += vel;
    
}

//--------------------------------------------------------------
void Player::draw(){
    
    //player
    ofPushMatrix();
    ofTranslate(cX, cY);
//    ofSetColor(222,54,49);
    ofSetColor(245,80,70,255);
    ofRotateZ(pRotateAng);
    ofRotateX(pRotateX);
    playerImg.draw(pPos.x, pPos.y, pPos.z,42,42);
    
    //follower
    ofPushStyle();
    ofSetColor(245,80,70,180);
    ofDrawCircle(pos.x, pos.y, scale);
    ofPopMatrix();
    ofPopStyle();
    
}

//--------------------------------------------------------------
void Player::keyPressed(int key){
    if (key == OF_KEY_LEFT) {
        pAngle += 0.02;
        pRotateAng +=8.18;
    } else if(key ==OF_KEY_RIGHT){
        pAngle -= 0.02;
        pRotateAng -= 8.18;
    }
}
