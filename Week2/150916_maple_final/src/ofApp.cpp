#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup("Maple Leaves");
    
    
    gui.add(mapleWidth.set("Maple Width", 20,15,25));
    gui.add(mapleHeight.set("Maple Height", 60,50,70));
    gui.add(speed.set("Speed", 0,-0.1,0.15));
//    gui.add(musicButton.set("Music on/off", true));
    
    ofEnableAlphaBlending();
    ofEnableSmoothing();

    
    sound.loadSound("1.mp3");
    sound.play();
    
    bgColor1.set(247,231,210);
    bgColor2.set(207,193,168);
    numMaple = 20;
    
    for (int i = 0; i< numMaple; i++) {
        Maple tempMaple;
        tempMaple.setup();
        maples.push_back(tempMaple);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < numMaple ; i++) {
        maples[i].update();
        
        if (maples[i].pos.y > ofGetHeight()+60) {
            maples[i].pos.y = -40;
        }
        
        if (maples[i].pos.x > ofGetWidth()+100) {
            maples[i].pos.y = -40;
            maples[i].pos.x = ofRandom(20,ofGetWidth()-100);
        }

    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(bgColor1, bgColor2,OF_GRADIENT_CIRCULAR);
    
    
    for (int i = 0; i< numMaple; i++) {
        maples[i].draw();
        maples[i].leafW =mapleWidth;
         maples[i].leafH =mapleHeight;
        maples[i].acc.y =speed;
    }
    
    gui.draw();
    
    ofSetHexColor(0x000000);
    ofDrawBitmapString("KEY a: Spring", 15,110);
    ofDrawBitmapString("KEY s: Summer", 15,130);
    ofDrawBitmapString("KEY d: Autumn", 15,150);
    ofDrawBitmapString("KEY f: Winter", 15,170);
    ofDrawBitmapString("KEY space: fullScreen", 15,190);

    
    if(musicButton == true){
        sound.play();
//        sound.setLoop(true);
    }
//        else if(musicButton == false){
//        sound.stop();
//    }

    
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
