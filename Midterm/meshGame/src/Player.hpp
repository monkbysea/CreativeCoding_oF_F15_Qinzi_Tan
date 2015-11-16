//  Player.hpp
//  prot10
//  Created by Qinzi Tan on 11/1/15.


#ifndef Player_hpp
#define Player_hpp

#include "ofMain.h"

#endif /* Player_hpp */
#pragma once


class Player : public ofBaseApp{
    
public:
    
    Player();
    
    void setAttractPoints( vector <ofPoint> * attract );
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
private:
    
    float cX, cY;
    
    //for player
    ofVec3f pPos;
    ofVec3f pVel;
    ofColor pColor;
    float pR;
    float pAngle;
    float pRotateAng;
    
    float pRotateX;
    ofVec3f prePos;
    
    //for follower
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;
    
    float drag;
    float uniqueVal;
    float scale;
    
    vector <ofPoint> * attractPoints;
    ofVec2f attractPos;
    ofImage playerImg;
    
    
};
