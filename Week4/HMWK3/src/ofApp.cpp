#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    bgColor1.set(247,231,210);
    bgColor2.set(207,193,168);
    numMaple = 100;
    
    mainStemHeight = 250;
    mainStemWidth = 20;
    
    ofSetBackgroundAuto(false);
    
    bool hasDrawn = false;
    gui.setup("Maple Leaves");
    
    
    gui.add(mapleWidth.set("Maple Width", 20,15,25));
    gui.add(mapleHeight.set("Maple Height", 60,50,70));
    gui.add(speed.set("Speed", 0,-0.1,0.15));
    ofToggleFullscreen();
    ofEnableAlphaBlending();
    ofEnableSmoothing();

    
    ofBackgroundGradient(bgColor1, bgColor2,OF_GRADIENT_CIRCULAR);
    
    order = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    myImage.draw(0, 0, ofGetWidth(), ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    


    switch (key) {
        case 'a':
            ofBackgroundGradient(bgColor1, bgColor2,OF_GRADIENT_CIRCULAR);
            order = true;
            ofPushStyle();
            
            ofSetColor(99, 48, 20);
            ofRect(ofGetWidth()/2-mainStemWidth/2, 525, mainStemWidth, mainStemHeight);
            
            myBranch.setup(ofGetWidth()/2,
                           525,
                           mainStemWidth,
                           70,
                           0.80,
                           2,
                           6,
                           0,
                           1.5*PI,
                           0,
                           ofColor(99, 48, 20),
                           1);
            
            
            myRoot.setup(ofGetWidth()/2,
                         500+mainStemHeight,
                         mainStemWidth,
                         20,
                         0.80,
                         2,
                         5,
                         0,
                         2.5*PI,
                         0,
                         ofColor(99, 48, 20)
                         );
            ofPopStyle();
            
            myImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
            myImage.grabScreen(0, 0, ofGetWidth(),ofGetHeight());

            break;

        case 's':
            ofBackgroundGradient(bgColor1, bgColor2,OF_GRADIENT_CIRCULAR);
            order = true;
            ofPushStyle();
            
            ofSetColor(99, 48, 20);
            ofRect(ofGetWidth()/2-mainStemWidth/2, 525, mainStemWidth, mainStemHeight);
            
            myBranch.setup(ofGetWidth()/2,
                           525,
                           mainStemWidth,
                           70,
                           0.80,
                           2,
                           6,
                           0,
                           1.5*PI,
                           0,
                           ofColor(99, 48, 20),
                           2);
            
            
            myRoot.setup(ofGetWidth()/2,
                         500+mainStemHeight,
                         mainStemWidth,
                         20,
                         0.80,
                         2,
                         5,
                         0,
                         2.5*PI,
                         0,
                         ofColor(99, 48, 20)
                         );
            ofPopStyle();
            
            myImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
            myImage.grabScreen(0, 0, ofGetWidth(),ofGetHeight());
            
            break;

        case 'd':
            ofBackgroundGradient(bgColor1, bgColor2,OF_GRADIENT_CIRCULAR);
            order = true;
            ofPushStyle();
            
            ofSetColor(99, 48, 20);
            ofRect(ofGetWidth()/2-mainStemWidth/2, 525, mainStemWidth, mainStemHeight);
            
            myBranch.setup(ofGetWidth()/2,
                           525,
                           mainStemWidth,
                           70,
                           0.80,
                           2,
                           6,
                           0,
                           1.5*PI,
                           0,
                           ofColor(99, 48, 20),
                           3);
            
            
            myRoot.setup(ofGetWidth()/2,
                         500+mainStemHeight,
                         mainStemWidth,
                         20,
                         0.80,
                         2,
                         5,
                         0,
                         2.5*PI,
                         0,
                         ofColor(99, 48, 20)
                         );
            ofPopStyle();
            
            myImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
            myImage.grabScreen(0, 0, ofGetWidth(),ofGetHeight());
            
            break;

        case 'f':
            ofBackgroundGradient(bgColor1, bgColor2,OF_GRADIENT_CIRCULAR);
            order = true;
            ofPushStyle();
            
            ofSetColor(99, 48, 20);
            ofRect(ofGetWidth()/2-mainStemWidth/2, 525, mainStemWidth, mainStemHeight);
            
            myBranch.setup(ofGetWidth()/2,
                           525,
                           mainStemWidth,
                           70,
                           0.80,
                           2,
                           6,
                           0,
                           1.5*PI,
                           0,
                           ofColor(99, 48, 20),
                           4);
            
            
            myRoot.setup(ofGetWidth()/2,
                         500+mainStemHeight,
                         mainStemWidth,
                         20,
                         0.80,
                         2,
                         5,
                         0,
                         2.5*PI,
                         0,
                         ofColor(99, 48, 20)
                         );
            ofPopStyle();
            
            myImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
            myImage.grabScreen(0, 0, ofGetWidth(),ofGetHeight());
            
            break;

            
                default:
        break;
      }
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    }

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    }

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
