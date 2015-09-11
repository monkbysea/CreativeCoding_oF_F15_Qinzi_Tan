//
//  Leaf.h
//  150910_ofClass_leaf
//
//  Created by Qinzi Tan on 9/10/15.
//
//

#ifndef ___50910_ofClass_leaf__Leaf__
#define ___50910_ofClass_leaf__Leaf__

#include "ofMain.h"

class Leaf : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    float xPos, yPos;
    float leafLength, leafWidth;
    float stemLength, stemWidth;
    float rotation;
    ofColor stemColor;
    ofColor leafColor;
    
    float scaleFactor;
    float shapeChange;

};

#endif /* defined(___50910_ofClass_leaf__Leaf__) */
