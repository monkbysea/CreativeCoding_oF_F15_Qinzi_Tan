//
//  Branch.h
//  150916_maple_final
//
//  Created by Qinzi Tan on 9/22/15.
//
//

#ifndef ___50916_maple_final__Branch__
#define ___50916_maple_final__Branch__

#include "ofMain.h"
#include "Maple.h"


class Branch : public ofBaseApp{
    
public:
    void setup(float _xPos, float _yPos, float _width,
               float _length,
               float _splitPercentage,
               int _maxSubdivisions,
               int _maxSegments,
               int _segmentsSinceStart,
               float _angle,
               float _curvature,
               ofColor _color);
    void update();
    void draw();
    
    
private:
    
    float xPos, yPos;
    float width, length;
    float splitPercentage;
    int maxSubdivsions;
    int maxSegments;
    int segmentsSinceStart;
    float angle;
    float curvature;
    bool hasLeaves;
    ofColor color;

    Maple myMaple;
    
    ofVec2f maplePos;
};

#endif /* defined(___50916_maple_final__Branch__) */
