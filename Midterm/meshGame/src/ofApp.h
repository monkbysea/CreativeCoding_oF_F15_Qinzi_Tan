#pragma once

#include "ofMain.h"
#include "Player.hpp"
#include "Cube.hpp"
#include "Particle.hpp"

#define NUM 165
#define N 256
#define n 300
#define playerNUM 60
#define starNUM 600

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    ofMesh mesh;
    
    ofLight light;
    
    
    ofVec3f pos[NUM];
    vector<ofVec3f> vertex;
    
    float w,h;
    float z[15];
    
    float angle;
    float r;
    
    float rAngle;
    float vel;
    float acc;
    
    ofSoundPlayer sound;
    
    float spectrum[N];
    float move;
    float velS;
    int specMove = 2;
    int specVel = 100;
    
    
    float tx[n], ty[n],tz[n];
    float time0 = 0;
    
    
    vector<Player> myPlayer;
    vector <ofPoint> attractPoints;
    vector <ofPoint> attractPointsWithMovement;
    
    vector<Cube> cubes;
    int counter;
    
    ofEasyCam cam;
    
    vector<Particle> stars;
    
    //gaming
    bool isAlive;
};
