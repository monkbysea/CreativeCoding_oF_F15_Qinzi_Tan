//
//  FlowField.hpp
//  flowFieldProt1
//
//  Created by Qinzi Tan on 11/29/15.
//
//

#ifndef FlowField_hpp
#define FlowField_hpp

#include "ofMain.h"

#endif /* FlowField_hpp */

class FlowField {
    
public:
    void setupField(int innerW, int innerH, int outerW, int outerH);
    void clear();
    void fadeField(float fadeAmount);
    void randomizeField(float scale);
    
    void draw();
    
    
    ofVec2f	getForceFromPos(float xpos, float ypos);    
    void addClockwiseCircle(float x, float y, float radius, float strength);

    int fieldWidth;
    int fieldHeight;
    int fieldSize;
    
    int externalWidth;
    int externalHeight;
    
    vector <ofVec2f> field;
    
    
    
};
