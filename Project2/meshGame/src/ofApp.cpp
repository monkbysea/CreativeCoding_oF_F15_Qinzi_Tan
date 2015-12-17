#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    mesh.enableColors();
    mesh.enableIndices();
    ofToggleFullscreen();
    
    isAlive = true;
    
    //    cam.setDistance(700);
    
    w = ofGetWidth();
    h = ofGetHeight();
    
    r = 200;
    rAngle = 40;
    
    sound.load("sounds/me.mp3");
    sound.setLoop(true);
    sound.play();
    
    for (int i=0; i<N; i++) {
        spectrum[i] = 0.0f;
    }
    
    //player
    for(int i = 0; i < myPlayer.size(); i++){
        ofPushStyle();
        ofSetColor(255, 0, 0);
        myPlayer[i].draw();
        ofPopStyle();
    }
    
    //mesh
    for (int i = 0; i<NUM; i++) {
//        mesh.addColor(ofFloatColor(0.914, 0.69, 0.549));
//        mesh.addColor(ofFloatColor(0.945, 0.894, 0.659));
//        mesh.addColor(ofFloatColor(0.902, 0.431, 0.424));
        
        mesh.addColor(ofFloatColor(0.322, 0.757, 0.714, 0.9));
        mesh.addColor(ofFloatColor(0.945, 0.616, 0.678 , 0.9));
        mesh.addColor(ofFloatColor(0.808, 0.914, 0.886, 0.9));

    }
    
    
    //move
    for (int j = 0; j<15; j++) {
        z[j] = 300 - j*25;
    }
    cout << "vertex :"<< vertex.size()<< endl;
    
    //player
    myPlayer.assign(playerNUM, Player());
    
    for (int i=0; i<playerNUM; i++) {
        Player tempP;
        tempP.setup();
        myPlayer.push_back(tempP);
    }
    
    //cube
    for (int i = 0; i< 5; i++) {
        Cube tempCube;
        tempCube.setup();
        cubes.push_back(tempCube);
    }
    
    //galaxy
    for (int i = 0; i< starNUM; i++) {
        Particle star;
        star.setup();
        stars.push_back(star);
    }
    
    counter = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    //player
    for(int i = 0; i < myPlayer.size(); i++){
        myPlayer[i].update();
    }
    
    //sound
    ofSoundUpdate();
    float *data = ofSoundGetSpectrum(N);
    
    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.8;
        spectrum[i] = max(spectrum[i], data[i]);
    }
    
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp(dt, 0.0, 0.1);
    time0 = time;
    
    move = ofMap(spectrum[specMove], 1, 3, 2, 5, true);
    velS = ofMap(spectrum[specVel], 0, 0.1, 1.5,10.5);
    cout << "velS: " << velS << endl;
    
    //cubes
    for(auto &it:z){
        it += velS;
    }
    
    for (auto &it:cubes) {
        it.update(velS*0.7);
    }
    
    
    //mesh
    mesh.clearVertices();
    
    for (int i = 0; i< NUM; i++) {
        tx[i] += velS * dt;
        ty[i] += velS * dt;
        
        if (i<11) {
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z = z[0];
            
        }
        
        else if (i>=11 && i<22){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z = z[1];
            
        }
        
        else if (i>=22 && i<33){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z =z[2];
        }
        
        else if (i>=33 && i<44){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z =z[3];
        }
        
        else if (i>=44 && i<55){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z =z[4];
        }
        
        else if (i>=55 && i<66){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z =z[5];
        }
        
        else if (i>=66 && i<77){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z =z[6];
        }
        
        else if (i>=77 && i<88){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z =z[7];
        }
        
        else if (i>=88 && i<99){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z = z[8];
        }
        
        else if (i>=99 && i<110){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z = z[9];
        }
        
        else if (i>=110 && i<121){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z = z[10];
        }
        
        else if (i>=121 && i<132){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z = z[11];
        }
        
        else if (i>=132 && i<143){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z = z[12];
        }
        
        
        else if (i>=143 && i<154){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z = z[13];
        }
        
        
        else if (i>=154 && i<165){
            
            pos[i].y = r * sin(ofDegToRad(i*(360/10)));
            pos[i].x = r * cos(ofDegToRad(i*(360/10)));
            pos[i].z = z[14];
        }
        
        vertex.push_back(pos[i]);
        mesh.addVertex(pos[i]);
    }
    
    for (auto &it:z){
        if (it>490+150) {
            it = 115+150;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(32,52,91);
    
    //galaxy
    for (auto &it:stars) {
        it.draw();
    }
    
    //mesh
    ofPushMatrix();
    ofTranslate(w/2, h/2);
    ofRotateZ(rAngle);
    mesh.draw();
    ofPopMatrix();
    
    //player
    for(int i = 0; i < myPlayer.size(); i++){
        ofPushStyle();
        ofSetColor(255, 0, 0);
        myPlayer[i].draw();
        ofPopStyle();
    }
    
    //cubes
    for (auto &it:cubes) {
        it.draw();
    }
    
    //    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(int i = 0; i < myPlayer.size(); i++){
        myPlayer[i].keyPressed(key);
    }
    
}
