//
//  Particle.hpp
//  OF_Firework_1
//
//  Created by Qinzi Tan on 10/13/15.
//
//

#ifndef Particle_hpp
#define Particle_hpp

#include "ofMain.h"

#endif /* Particle_hpp */

class Particle : public ofBaseApp{
    
public:
    void setup(
               float _posX,
               float _posY,
               float _velX,
               float _velY,
               float _accX,
               float _accY,
               float _diameter,
               ofColor _particleColor
//               ofColor _burstAddColor
    );
    
    void update();
    void draw();
    void goBurst();

    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
//private:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    float diameter;
    ofColor particleColor;
    
    //for burst
    ofVec2f velBurst;
    ofVec2f accBurst;
    ofColor colorBurst;
    float r;
    
    ofColor burstColor;
    float brightness;
    
    int velState;
 
    ofColor burstAddColor;
    
    int stateColor;
    
    
};
