#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Star.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
        void systemStart();
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
		
//    Particle myFirework;
  
    
    vector<Particle> firework;
    
    vector<Star> stars;
    int starNum;
    
    ofColor fireColor;
    float startX;
    float startY;
    
    ofColor color1;
    ofColor color2;
    ofColor color3;
    ofColor color4;
    ofColor color5;
    ofColor color6;
    
    int colorState;
    float brightness;
};
