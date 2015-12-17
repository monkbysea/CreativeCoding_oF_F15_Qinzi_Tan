#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    bgC1.set(1,15,33);
    bgC2.set(3, 129, 178);
    
//    ofBackgroundGradient(bgC1, bgC2, OF_GRADIENT_CIRCULAR);
    ofBackground(bgC1);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofToggleFullscreen();
    
    sound.load("sounds/1.mp3");
    sound.setLoop(true);
    sound.play();

//    camera.setFov(60);
//    camera.setPosition(0,200, ofGetWidth()/3);
//    camera.lookAt(ofVec3f(0,200,0));

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetRectMode(OF_RECTMODE_CENTER);

    leap.open();
    leap.setupGestures();
    
    for (int i = 0; i < 2800; i++){
        particle myParticle;
        myParticle.setInitialCondition
        (ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
        particles.push_back(myParticle);
    }
    
    
    VF.setupField(102, 76, ofGetWidth(), ofGetHeight());
    
}


//--------------------------------------------------------------
void ofApp::update(){
    leap.updateGestures();  // check for gesture updates
    leap.markFrameAsOld();	//I
    sound.setPan(pan);
    sound.setVolume(volume);
    
    
    //flowField
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].resetForce();
        
        ofVec2f frc;
        frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
        
        particles[i].addForce(frc.x, frc.y);
        particles[i].addDampingForce();
        particles[i].bounceOffWalls();
        particles[i].update();
    }
    
    VF.fadeField(0.998f);
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //LEAP
    ofPushStyle();
    Leap::Frame frame = controller.frame();
    
    Leap::Hand panHand = frame.hands()[0];
    pan = ofMap(panHand.palmPosition().x, -200, 200, -1, 1);
    volume = ofMap(panHand.palmPosition().y, 0, 300, 0, 1);
    
        Leap::Hand fieldHand = frame.hands()[0];
    vfPos.x = ofMap(fieldHand.palmPosition().x, -200, 200, 0, ofGetWidth());
    vfPos.y = ofMap(fieldHand.palmPosition().y,0, 300, ofGetHeight(), 0);
    cout << "palmPosition.y:" << panHand.palmPosition().y << endl;
    
//    ofPushMatrix();
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    VF.addClockwiseCircle(vfPos.x, vfPos.y, 80, 0.05);
//    ofPopMatrix();
    
    
    for (int i = 0; i<frame.hands().count(); i++) {
        Leap::Hand hand = frame.hands()[i];
//        DrawSphere(hand.palmPosition(),20);
        
        for(int j = 0; j < hand.fingers().count();j++){
            Leap::Finger finger = frame.fingers()[j];
//            DrawSphere(finger.tipPosition(), 8);
            
            if(leap.iGestures == 2){
                if (finger.tipPosition().x<ofGetWidth()/2+25 &&
                    finger.tipPosition().x > ofGetWidth()/2+25 &&
                    finger.tipPosition().y > ofGetHeight()/2 - 25 &&
                    finger.tipPosition().y < ofGetHeight()/2 +25
                    ) {
                    ofDrawRectangle(200, 200, 50, 50);
                }
            }
        }
    }

    float currentSwipeSpeed = swipe.speed();
    
    ofPopStyle();

    
    //particle & flowField
    ofPushStyle();
//    ofSetColor(255, 255, 255);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //DISPLAY FLOWFIELD
//    ofSetColor(0,130,130, 127);
//    VF.draw();
    
    ofSetColor(255);
    for (int i = 0; i < particles.size(); i++){
        pColor.set(ofRandom(170,240));
        particles[i].draw(pColor);
    }
    ofDisableBlendMode();
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

//--------------------------------------------------------------
void ofApp::DrawSphere(Leap::Vector vector, float radius){

    ofNoFill ();
    ofPushMatrix ();
    ofPoint point = ofPoint (vector.x, vector.y, vector.z);
    ofTranslate (point);
    ofRotateX (point.x);
    ofRotateY (point.y);
    ofRotateZ (point.z);
    ofSetColor (0xCC, 0,0,255);
    ofDrawSphere (radius);
    ofPopMatrix ();

}