#pragma once

#include "ofMain.h"
#include "Leap.h"
#include "ofxLeapMotion.h"
#include "FlowField.hpp"
#include "particle.hpp"

class ofApp : public ofBaseApp{

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void DrawSphere(Leap::Vector vector, float radius);
		
    Leap::Controller controller;
    ofCamera camera;
    
    Leap::Vector swipeDirection;
    Leap::SwipeGesture swipe;
    
    ofSoundPlayer sound;
    ofxLeapMotion leap;
    float pan;
    float volume;
    
    ofColor pColor;
    
    
    FlowField VF;
    vector <particle> particles;
    
    int addMode;
    ofVec2f vfPos;
    
    ofColor bgC1;
    ofColor bgC2;
    
};
