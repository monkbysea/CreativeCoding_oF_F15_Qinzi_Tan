//
//  Star.hpp
//  OF_Firework_1
//
//  Created by Qinzi Tan on 10/13/15.
//
//

#ifndef Star_hpp
#define Star_hpp

#include "ofMain.h"

#endif /* Star_hpp */

class Star : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

private:
    
    ofVec3f pos;
    ofVec3f vel;
    ofVec3f acc;
    float radius;
    ofColor starColor;
    ofSpherePrimitive sphere;
    float spinX;
    float spinY;
};
