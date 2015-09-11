//
//  Leaf.cpp
//  150910_ofClass_leaf
//
//  Created by Qinzi Tan on 9/10/15.
//
//

#include "Leaf.h"

//--------------------------------------------------------------
void Leaf::setup(){
    
//    float xPos, yPos;
//    float leafLength, leafWidth;
//    float stemLength, stemWidth;
//    float rotation;
//    ofColor stemColor;
//    float scaleFactor;

    
    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    
    leafLength = ofRandom(130,160);
    leafWidth = ofRandom(80,105);
    stemLength = ofRandom(80,100);
    stemWidth = ofRandom(3,10);
    rotation = ofRandom(0,360);
    stemColor = ofColor(130,50,20);
    leafColor = ofColor(ofRandom(0,20), ofRandom(150,255), ofRandom(0,20),ofRandom(225,255));
    
    scaleFactor = ofRandom(.8,1.4);
    shapeChange = ofRandom(2,6);
}

//--------------------------------------------------------------
void Leaf::update(){
    
}

//--------------------------------------------------------------
void Leaf::draw(){
    
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    ofScale(scaleFactor, scaleFactor);
    ofRotateZ(rotation);
//    ofRotateX(rotation);
    ofRotateY(rotation);
    
    ofSetColor(leafColor);
  
    
    ofBeginShape();
    
    float x0 = 0;
    float x1 = x0 - leafWidth;
    float x2 = x0 - leafWidth/shapeChange;
    float x3 = x0;
    
    float y0 = 0 - stemLength;
    float y1 = y0 - leafLength/3;
    float y2 = y1 - leafLength/shapeChange;
    float y3 = y0 - leafLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    

    
    ofBeginShape();
    
    x0 = 0;
    x1 = x0 + leafWidth;
    x2 = x0 + leafWidth/shapeChange*.8;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafLength/shapeChange*.8;
    y2 = y1 - leafLength/3;
    y3 = y0 - leafLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();

    
    
    ofSetColor(stemColor);
    ofRect(0,0 - (stemLength/2), stemWidth, stemLength);
    ofTriangle(0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(leafLength/4));
    
    ofPopMatrix();
        
}


