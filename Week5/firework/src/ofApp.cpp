#include "ofApp.h"

bool shouldRemove(Particle &it){
    if(it.pos.x > ofGetWidth()
       || it.pos.x < 0
       || it.pos.y > ofGetHeight()
       )return true;
    
    else return false;
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(true);
    ofEnableSmoothing();
    ofSetCircleResolution(70);
    ofToggleFullscreen();
    
    brightness = 200;
    
    starNum = 150;
    
    for(int i = 0; i < starNum; i++){
        Star tempStar;
        tempStar.setup();
        stars.push_back(tempStar);
    }

}


//--------------------------------------------------------------
void ofApp::systemStart(){


    for (int i = 0; i< 300; i++ ) {
        Particle tempFire;
        tempFire.setup(startX,
                       startY,
                       0,
                       -35,
                       0,
                       .98,
                       2.3,
                       fireColor);
        firework.push_back(tempFire);
    }
    
    //void Particle::setup(float _posX,
    //                     float _posY,
    //                     float _velX,
    //                     float _velY,
    //                     float _accX,
    //                     float _accY,
    //                     float _diameter,
    //                     ofColor _particleColor)
    
}



//--------------------------------------------------------------
void ofApp::update(){
    
    for (auto &it:stars) {
        it.update();
    }
    
    for (auto &it:firework) {
        it.update();
        
    }
    
    if(brightness >0){
    brightness -= 199;
    cout<<brightness<<endl;
    }
    
    ofRemove(firework,shouldRemove);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    color1.set(122,188,231,brightness);
    color2.set(233,68,44,brightness);
    color3.set(152,194,29,brightness);
    color4.set(250,231,28,brightness);
    color5.set(220,218,217,brightness);
    color6.set(0, 0, 0);
    
    colorState = int(ofRandom(1,6));
    
    if (colorState ==1) {
        fireColor = color1;
    } else if (colorState ==2 ){
        fireColor = color2;
    } else if (colorState == 3){
        fireColor = color3;
    } else if (colorState == 4){
        fireColor = color4;
    } else if (colorState == 5){
        fireColor = color5;
    }
    

    for (auto &it:stars) {
        it.draw();
    }
    
    for (auto &it:firework) {
        it.draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        startX = ofRandom(ofGetWidth()*.5-400,ofGetWidth()/2+400);
        startY = ofRandom(ofGetHeight()*.9,ofGetHeight()*1.06);
        systemStart();
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
    
    for (int i = 0; i< 100; i++ ) {
        Particle tempFire;
        tempFire.setup(mouseX,
                       mouseY,
                       0,
                       0,
                       0,
                       .98,
                       2.3,
                       fireColor);
        firework.push_back(tempFire);
        
        if(tempFire.vel.y>2){
            tempFire.particleColor.set(0, 0, 0);
        }
    }
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
