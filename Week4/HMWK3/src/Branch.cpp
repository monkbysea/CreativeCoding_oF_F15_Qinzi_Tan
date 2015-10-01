//
//  Branch.cpp
//  150916_maple_final
//
//  Created by Qinzi Tan on 9/22/15.
//
//

#include "Branch.h"

//--------------------------------------------------------------
void Branch::setup(float _xPos,
                   float _yPos,
                   float _width,
                   float _length,
                   float _splitPercentage,
                   int _maxSubdivisions,
                   int _maxSegments,
                   int _segmentsSinceStart,
                   float _angle,
                   float _curvature,
                   ofColor _color, int _season){

    
    xPos = _xPos;
    yPos = _yPos;
    width = _width;
    length = _length;
    splitPercentage = _splitPercentage;
    maxSubdivsions = _maxSubdivisions;
    maxSegments = _maxSegments;
    segmentsSinceStart = _segmentsSinceStart;
    angle = _angle;
    curvature = _curvature;
    color = _color;
    season = _season;
    

    myMaple.setup();
    
    mapleColor = myMaple.leafColor;
    
    if (_season == 1) {
        myMaple.leafColor = myMaple.leafColor1;
    } else if (_season == 2) {
        myMaple.leafColor = myMaple.leafColor2;
    } else if (_season == 3) {
        myMaple.leafColor = myMaple.leafColor3;
    } else if (_season == 4){
        myMaple.leafColor = myMaple.leafColor4;
    }
    
    
    ofSetColor(color);
    ofSetLineWidth((int)width);
    ofLine(xPos, yPos, xPos + length*cos(angle), yPos + length*sin(angle));

    xPos += length*cos(angle);
    yPos += length*sin(angle);
    width = width*(ofRandom(0.5,0.8));
    segmentsSinceStart += 1;
    angle += curvature;
    curvature += ofRandom(0, (float)(2*PI)/360.0);
    
    maplePos.set(xPos,yPos);
    
    myMaple.drawLeftSide(maplePos);
    myMaple.drawRightSide(maplePos);
    
    if (segmentsSinceStart <= maxSegments) {
        if(ofRandom(0, 1) > splitPercentage){
            Branch subBranch;
            subBranch.setup(xPos, yPos, width, length, splitPercentage, maxSubdivsions, maxSegments, segmentsSinceStart, angle, curvature, color, season);
        } else {
            Branch subBranch1;
            float angle1 = angle + ofRandom(0,2.8*(PI/8));
            Branch subBranch2;
            float angle2 = angle - ofRandom(0,2.8*(PI/8));
            
            subBranch1.setup(xPos, yPos, width, length, splitPercentage, maxSubdivsions, maxSegments, segmentsSinceStart, angle1, curvature, color, season);
            
            subBranch2.setup(xPos, yPos, width, length, splitPercentage, maxSubdivsions, maxSegments, segmentsSinceStart, angle2, curvature, color, season);
        }
    }
}

//--------------------------------------------------------------
void Branch::update(){
    
}

//--------------------------------------------------------------
void Branch::draw(){
    
}