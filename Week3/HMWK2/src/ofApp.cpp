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
    
    
    for (int i = 0; i< numMaple; i++) {
        Maple tempMaple;
        tempMaple.setup();
        maples.push_back(tempMaple);
    }
    
    order = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
//    gui.draw();
    
//    ofSetHexColor(0x000000);
//    ofDrawBitmapString("KEY a: Spring", 15,110);
//    ofDrawBitmapString("KEY s: Summer", 15,130);
//    ofDrawBitmapString("KEY d: Autumn", 15,150);
//    ofDrawBitmapString("KEY f: Winter", 15,170);
//    ofDrawBitmapString("KEY space: fullScreen", 15,190);

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for (int i = 0; i< numMaple; i++) {

    switch (key) {
        case 'a':
            maples[i].leafColor = maples[i].leafColor1;
            break;
            
        case 's':
            maples[i].leafColor = maples[i].leafColor2;
            break;
            
        case 'd':
            maples[i].leafColor = maples[i].leafColor3;
            break;
            
        case 'f':
            maples[i].leafColor = maples[i].leafColor4;
            break;
            
        default:
        break;
    }
    }
    
    if (key == ' ') {
        ofToggleFullscreen();
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
    ofBackgroundGradient(bgColor1, bgColor2,OF_GRADIENT_CIRCULAR);
    order = true;
//    for (int i = 0; i< numMaple; i++) {
//        if(order == true){
//            maples[i].draw();
//            maples[i].leafW =mapleWidth;
//            maples[i].leafH =mapleHeight;
//            maples[i].acc.y =speed;
//            
//            ofSetColor(99, 48, 20);
//            ofRect(ofGetWidth()/2-mainStemWidth/2, 500, mainStemWidth, mainStemHeight);
//        }
//    }
    

    ofSetColor(99, 48, 20);
                ofRect(ofGetWidth()/2-mainStemWidth/2, 520, mainStemWidth, mainStemHeight);
    
    myBranch.setup(ofGetWidth()/2,
                   520,
                   mainStemWidth,
                   70,
                   0.80,
                   2,
                   6,
                   0,
                   1.5*PI,
                   0,
                   ofColor(99, 48, 20)
                   );
    
    myRoot.setup(ofGetWidth()/2,
                   520+mainStemHeight,
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
    
//    subBranch1.setup(xPos, yPos, width, length, splitPercentage, maxSubdivsions, maxSegments, segmentsSinceStart, angle1, curvature, color);

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
