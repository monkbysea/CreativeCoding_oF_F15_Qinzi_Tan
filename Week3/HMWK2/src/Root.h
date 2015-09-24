//
//  Root.h
//  150916_maple_final
//
//  Created by Qinzi Tan on 9/24/15.
//
//

#ifndef ___50916_maple_final__Root__
#define ___50916_maple_final__Root__

#include "ofMain.h"


class Root : public ofBaseApp{
    
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
    
    
};


#endif /* defined(___50916_maple_final__Root__) */
