//
//  Maple.cpp
//  150916_maple_final
//
//  Created by Qinzi Tan on 9/16/15.
//
//

#include "Maple.h"

//--------------------------------------------------------------
void Maple::setup(){
    
    
    pos.set(ofRandom(20,ofGetWidth()-20),ofRandom(-300,300));
    vel.set(ofRandom(0.05,0.3),ofRandom(0.7,2.7));
    acc.set(0,0);
    
    
    leafColor1.set(155,189,22);
    leafColor2.set(159,167,57);
    leafColor3.set(199,77,41);
    leafColor4.set(143,83,4);
    
    leafColor.set(leafColor3);
    
    stemColorH.set(99, 48, 20);
    stemWH = 2;
    stemHH = 45;
    
        leafW = 20;
        leafH = 60;
    
    stemW = 2;
    stemH = 40;
    
    rotation = ofRandom(140,220);
    
    rotationVel = 1;
    
    
}

//--------------------------------------------------------------
void Maple::update(){
    pos += vel;
    
    vel += acc;
    
    
    if(rotation == 225) {
        rotationVel = -rotationVel;
    }
    
    
    rotation += rotationVel;
}

//--------------------------------------------------------------
void Maple::draw(){

    drawLeftSide();
    drawRightSide();
    
}

//--------------------------------------------------------------
void Maple::drawLeftSide(){
    
    //stage 1
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotation);
    ofSetColor(leafColor);
    ofSetLineWidth(3);
    float x0 = 0;
    float x1 = 0;
    float x2 = 0;
    float x3 = -0.3 * leafW;
    
    float y0 = -(leafH-0);
    float y1 = -(leafH-(leafH * 1.8)/32);
    float y2 = -(leafH-(leafH*6.8)/32);
    float y3 = -(leafH-(leafH*5.4)/32);
    
    
    float x4 = -0.16*leafW;
    float x5 = -0.5*leafW;
    float x6 = -0.65*leafW;
    
    float y4 = -(leafH-(leafH*8.7)/32);
    float y5 = -(leafH-(10*leafH)/32);
    float y6 = -(leafH-(8*leafH)/32);
    
    
    float x7 = -0.35 * leafW;
    float x8 = -0.75 * leafW;
    float x9 = -leafW;
    
    float y7 = -(leafH-(13.2 * leafH)/32);
    float y8 = -(leafH-(15.6 * leafH)/32);
    float y9 = -(leafH-(17*leafH)/32);
    
    
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofBezierVertex(x4,y4,x5,y5,x6,y6);
    ofBezierVertex(x7,y7,x8,y8,x9,y9);
    ofVertex(0, 0);
    ofEndShape();
    
    ofSetColor(stemColorH);
    ofTriangle(-stemWH/2, 0, 0,0, 0,-stemHH);
    
    ofRect(-stemW * 0.5, -2, stemW, stemH);
    
    ofPopMatrix();
    
    
    
    //stage 2
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotation+50);
    ofSetColor(leafColor);
    ofSetLineWidth(3);
    x0 = 0;
    x1 = 0;
    x2 = 0;
    x3 = -0.3 * leafW;
    
    y0 = -(leafH-0);
    y1 = -(leafH-(leafH * 1.8)/32);
    y2 = -(leafH-(leafH*6.8)/32);
    y3 = -(leafH-(leafH*5.4)/32);
    
    
    x4 = -0.16*leafW;
    x5 = -0.5*leafW;
    x6 = -0.65*leafW;
    
    y4 = -(leafH-(leafH*8.7)/32);
    y5 = -(leafH-(10*leafH)/32);
    y6 = -(leafH-(8*leafH)/32);
    
    
    x7 = -0.35 * leafW;
    x8 = -0.75 * leafW;
    x9 = -leafW;
    
    y7 = -(leafH-(13.2 * leafH)/32);
    y8 = -(leafH-(15.6 * leafH)/32);
    y9 = -(leafH-(17*leafH)/32);
    
    
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofBezierVertex(x4,y4,x5,y5,x6,y6);
    ofBezierVertex(x7,y7,x8,y8,x9,y9);
    ofVertex(0, 0);
    ofEndShape();
    ofSetColor(stemColorH);
    ofTriangle(-stemWH/2, 0, 0,0, 0,-stemHH);
    
    ofPopMatrix();
    
    //stage 3
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotation+100);
    ofSetColor(leafColor);
    ofSetLineWidth(3);
    x0 = 0;
    x1 = 0;
    x2 = 0;
    x3 = -0.3 * leafW;
    
    y0 = -(leafH-0);
    y1 = -(leafH-(leafH * 1.8)/32);
    y2 = -(leafH-(leafH*6.8)/32);
    y3 = -(leafH-(leafH*5.4)/32);
    
    
    x4 = -0.16*leafW;
    x5 = -0.5*leafW;
    x6 = -0.65*leafW;
    
    y4 = -(leafH-(leafH*8.7)/32);
    y5 = -(leafH-(10*leafH)/32);
    y6 = -(leafH-(8*leafH)/32);
    
    
    x7 = -0.35 * leafW;
    x8 = -0.75 * leafW;
    x9 = -leafW;
    
    y7 = -(leafH-(13.2 * leafH)/32);
    y8 = -(leafH-(15.6 * leafH)/32);
    y9 = -(leafH-(17*leafH)/32);
    
    
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofBezierVertex(x4,y4,x5,y5,x6,y6);
    ofBezierVertex(x7,y7,x8,y8,x9,y9);
    ofVertex(0, 0);
    ofEndShape();
    
    ofSetColor(stemColorH);
    ofTriangle(-stemWH/2, 0, 0,0, 0,-stemHH);
    
    
    ofPopMatrix();
    
    
    //stage 4
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotation-50);
    ofSetColor(leafColor);
    ofSetLineWidth(3);
    x0 = 0;
    x1 = 0;
    x2 = 0;
    x3 = -0.3 * leafW;
    
    y0 = -(leafH-0);
    y1 = -(leafH-(leafH * 1.8)/32);
    y2 = -(leafH-(leafH*6.8)/32);
    y3 = -(leafH-(leafH*5.4)/32);
    
    
    x4 = -0.16*leafW;
    x5 = -0.5*leafW;
    x6 = -0.65*leafW;
    
    y4 = -(leafH-(leafH*8.7)/32);
    y5 = -(leafH-(10*leafH)/32);
    y6 = -(leafH-(8*leafH)/32);
    
    
    x7 = -0.35 * leafW;
    x8 = -0.75 * leafW;
    x9 = -leafW;
    
    y7 = -(leafH-(13.2 * leafH)/32);
    y8 = -(leafH-(15.6 * leafH)/32);
    y9 = -(leafH-(17*leafH)/32);
    
    
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofBezierVertex(x4,y4,x5,y5,x6,y6);
    ofBezierVertex(x7,y7,x8,y8,x9,y9);
    ofVertex(0, 0);
    ofEndShape();
    
    ofSetColor(stemColorH);
    ofTriangle(-stemWH/2, 0, 0,0, 0,-stemHH);
    
    ofPopMatrix();
    
    
    
    //stage 5
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotation-100);
    ofSetColor(leafColor);
    ofSetLineWidth(3);
    x0 = 0;
    x1 = 0;
    x2 = 0;
    x3 = -0.3 * leafW;
    
    y0 = -(leafH-0);
    y1 = -(leafH-(leafH * 1.8)/32);
    y2 = -(leafH-(leafH*6.8)/32);
    y3 = -(leafH-(leafH*5.4)/32);
    
    
    x4 = -0.16*leafW;
    x5 = -0.5*leafW;
    x6 = -0.65*leafW;
    
    y4 = -(leafH-(leafH*8.7)/32);
    y5 = -(leafH-(10*leafH)/32);
    y6 = -(leafH-(8*leafH)/32);
    
    
    x7 = -0.35 * leafW;
    x8 = -0.75 * leafW;
    x9 = -leafW;
    
    y7 = -(leafH-(13.2 * leafH)/32);
    y8 = -(leafH-(15.6 * leafH)/32);
    y9 = -(leafH-(17*leafH)/32);
    
    
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofBezierVertex(x4,y4,x5,y5,x6,y6);
    ofBezierVertex(x7,y7,x8,y8,x9,y9);
    ofVertex(0, 0);
    ofEndShape();
    
    ofSetColor(stemColorH);
    ofTriangle(-stemWH/2, 0, 0,0, 0,-stemHH);
    
    ofPopMatrix();
    
}


//--------------------------------------------------------------
void Maple::drawRightSide(){
    
    
    //stage 1
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotation);
    ofSetColor(leafColor);
    ofSetLineWidth(3);
    
    
    float x0 = 0;
    float x1 = 0;
    float x2 = 0;
    float x3 = 0.3 * leafW;
    
    float y0 = -(leafH-0);
    float y1 = -(leafH-(leafH * 1.8)/32);
    float y2 = -(leafH-(leafH*6.8)/32);
    float y3 = -(leafH-(leafH*5.4)/32);
    
    
    float x4 = 0.16*leafW;
    float x5 = 0.5*leafW;
    float x6 = 0.65*leafW;
    
    float y4 = -(leafH-(leafH*8.7)/32);
    float y5 = -(leafH-(10*leafH)/32);
    float y6 = -(leafH-(8*leafH)/32);
    
    
    float x7 = 0.35 * leafW;
    float x8 = 0.75 * leafW;
    float x9 = leafW;
    
    float y7 = -(leafH-(13.2 * leafH)/32);
    float y8 = -(leafH-(15.6 * leafH)/32);
    float y9 = -(leafH-(17*leafH)/32);
    
    
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofBezierVertex(x4,y4,x5,y5,x6,y6);
    ofBezierVertex(x7,y7,x8,y8,x9,y9);
    ofVertex(0 , 0);
    ofEndShape();
    
    ofSetColor(stemColorH);
    ofTriangle(stemWH/2, 0, 0,0, 0,-stemHH);
    ofRect(-stemW * 0.5, -2, stemW, stemH);
    
    ofPopMatrix();
    
    
    //stage 2
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotation+50);
    ofSetColor(leafColor);
    ofSetLineWidth(3);
    
    
    x0 = 0;
    x1 = 0;
    x2 = 0;
    x3 = 0.3 * leafW;
    
    y0 = -(leafH-0);
    y1 = -(leafH-(leafH * 1.8)/32);
    y2 = -(leafH-(leafH*6.8)/32);
    y3 = -(leafH-(leafH*5.4)/32);
    
    
    x4 = 0.16*leafW;
    x5 = 0.5*leafW;
    x6 = 0.65*leafW;
    
    y4 = -(leafH-(leafH*8.7)/32);
    y5 = -(leafH-(10*leafH)/32);
    y6 = -(leafH-(8*leafH)/32);
    
    
    x7 = 0.35 * leafW;
    x8 = 0.75 * leafW;
    x9 = leafW;
    
    y7 = -(leafH-(13.2 * leafH)/32);
    y8 = -(leafH-(15.6 * leafH)/32);
    y9 = -(leafH-(17*leafH)/32);
    
    
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofBezierVertex(x4,y4,x5,y5,x6,y6);
    ofBezierVertex(x7,y7,x8,y8,x9,y9);
    ofVertex(0,0);
    ofEndShape();
    
    ofSetColor(stemColorH);
    ofTriangle(stemWH/2, 0, 0,0, 0,-stemHH);
    
    
    ofPopMatrix();
    
    
    //stage 3
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotation-50);
    ofSetColor(leafColor);
    ofSetLineWidth(3);
    
    
    x0 = 0;
    x1 = 0;
    x2 = 0;
    x3 = 0.3 * leafW;
    
    y0 = -(leafH-0);
    y1 = -(leafH-(leafH * 1.8)/32);
    y2 = -(leafH-(leafH*6.8)/32);
    y3 = -(leafH-(leafH*5.4)/32);
    
    
    x4 = 0.16*leafW;
    x5 = 0.5*leafW;
    x6 = 0.65*leafW;
    
    y4 = -(leafH-(leafH*8.7)/32);
    y5 = -(leafH-(10*leafH)/32);
    y6 = -(leafH-(8*leafH)/32);
    
    
    x7 = 0.35 * leafW;
    x8 = 0.75 * leafW;
    x9 = leafW;
    
    y7 = -(leafH-(13.2 * leafH)/32);
    y8 = -(leafH-(15.6 * leafH)/32);
    y9 = -(leafH-(17*leafH)/32);
    
    
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofBezierVertex(x4,y4,x5,y5,x6,y6);
    ofBezierVertex(x7,y7,x8,y8,x9,y9);
    ofVertex(0,0);
    ofEndShape();
    
    ofSetColor(stemColorH);
    ofTriangle(stemWH/2, 0, 0,0, 0,-stemHH);
    
    ofPopMatrix();
    
    
    //stage 4
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotation-100);
    ofSetColor(leafColor);
    ofSetLineWidth(3);
    
    
    x0 = 0;
    x1 = 0;
    x2 = 0;
    x3 = 0.3 * leafW;
    
    y0 = -(leafH-0);
    y1 = -(leafH-(leafH * 1.8)/32);
    y2 = -(leafH-(leafH*6.8)/32);
    y3 = -(leafH-(leafH*5.4)/32);
    
    
    x4 = 0.16*leafW;
    x5 = 0.5*leafW;
    x6 = 0.65*leafW;
    
    y4 = -(leafH-(leafH*8.7)/32);
    y5 = -(leafH-(10*leafH)/32);
    y6 = -(leafH-(8*leafH)/32);
    
    
    x7 = 0.35 * leafW;
    x8 = 0.75 * leafW;
    x9 = leafW;
    
    y7 = -(leafH-(13.2 * leafH)/32);
    y8 = -(leafH-(15.6 * leafH)/32);
    y9 = -(leafH-(17*leafH)/32);
    
    
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofBezierVertex(x4,y4,x5,y5,x6,y6);
    ofBezierVertex(x7,y7,x8,y8,x9,y9);
    ofVertex(0,0);
    ofEndShape();
    
    ofSetColor(stemColorH);
    ofTriangle(stemWH/2, 0, 0,0, 0,-stemHH);
    
    
    
    ofPopMatrix();
    
    //stage 5
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotation+100);
    ofSetColor(leafColor);
    ofSetLineWidth(3);
    
    
    x0 = 0;
    x1 = 0;
    x2 = 0;
    x3 = 0.3 * leafW;
    
    y0 = -(leafH-0);
    y1 = -(leafH-(leafH * 1.8)/32);
    y2 = -(leafH-(leafH*6.8)/32);
    y3 = -(leafH-(leafH*5.4)/32);
    
    
    x4 = 0.16*leafW;
    x5 = 0.5*leafW;
    x6 = 0.65*leafW;
    
    y4 = -(leafH-(leafH*8.7)/32);
    y5 = -(leafH-(10*leafH)/32);
    y6 = -(leafH-(8*leafH)/32);
    
    
    x7 = 0.35 * leafW;
    x8 = 0.75 * leafW;
    x9 = leafW;
    
    y7 = -(leafH-(13.2 * leafH)/32);
    y8 = -(leafH-(15.6 * leafH)/32);
    y9 = -(leafH-(17*leafH)/32);
    
    
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofBezierVertex(x4,y4,x5,y5,x6,y6);
    ofBezierVertex(x7,y7,x8,y8,x9,y9);
    ofVertex(0,0);
    ofEndShape();
    
    ofSetColor(stemColorH);
    ofTriangle(stemWH/2, 0, 0,0, 0,-stemHH);
    
    
    
    ofPopMatrix();
    
    
}



//--------------------------------------------------------------
void Maple::keyPressed(int key){

}

