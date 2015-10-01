//
//  Maple.h
//  150916_maple_final
//
//  Created by Qinzi Tan on 9/16/15.
//
//

#ifndef ___50916_maple_final__Maple__
#define ___50916_maple_final__Maple__

#include "ofMain.h"
class Maple : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw(ofVec2f position);
    
    void drawLeftSide(ofVec2f pos);
    void drawRightSide(ofVec2f pos);
    
    void keyPressed(int key);
    
    
    ofVec2f pos1;
    ofVec2f vel;
    ofVec2f acc;

    
    ofColor leafColor;
    ofColor leafColor1;
    ofColor leafColor2;
    ofColor leafColor3;
    ofColor leafColor4;
    
    ofColor stemColorH;
    float stemWH;
    float stemHH;
    
    float leafW,leafH;
    
    float angle;
    
    
    float stemW;
    float stemH;
    
    float rotation;
    float rotationVel;
    
    
    
    
    
    
};


#endif /* defined(___50916_maple_final__Maple__) */
