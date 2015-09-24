#pragma once

#include "ofMain.h"
#include "Maple.h"
#include "Branch.h"
#include "ofxGui.h"
#include "Root.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofColor bgColor1;
    ofColor bgColor2;
    
    vector<Maple> maples;
    vector<Maple> maples2;
    vector<Maple> maples3;
    int numMaple;
		
    ofxPanel gui;
    
    ofParameter<int> mapleWidth;
    ofParameter<int> mapleHeight;
    ofParameter<float> speed;
    ofParameter<bool> musicButton;
    
    ofSoundPlayer sound;

    float mainStemWidth;
    float mainStemHeight;
    
    Branch myBranch;
      bool hasDrawn;
    
    Root myRoot;
    
    bool order;
};
