//
//  FlowField.cpp
//  flowFieldProt1
//
//  Created by Qinzi Tan on 11/29/15.


#include "FlowField.hpp"

//------------------------------------------------------------
void FlowField::setupField(int innerW, int innerH, int outerW, int outerH){
    
    fieldWidth = innerW;
    fieldHeight	= innerH;
    externalWidth = outerW;
    externalHeight = outerH;
    
    field.clear();
    
    fieldSize = fieldWidth * fieldHeight;
    for (int i = 0; i < fieldSize; i++){
        ofVec2f pt;
        pt.set(0,0);
        field.push_back(pt);
    }
}

//------------------------------------------------------------
void FlowField::clear(){
    for (int i = 0; i < fieldSize; i++){
        field[i].set(0,0);
    }
}

//------------------------------------------------------------
void FlowField::fadeField(float fadeAmount){
    for (int i = 0; i < fieldSize; i++){
        field[i].set(field[i].x*fadeAmount,field[i].y*fadeAmount);
    }
}

//------------------------------------------------------------
void FlowField::randomizeField(float scale){
    for (int i = 0; i < fieldSize; i++){
        float x = (float)(ofRandom(-1,1)) * scale;
        float y = (float)(ofRandom(-1,1)) * scale;
        field[i].set(x,y);
    }
}


//------------------------------------------------------------
void FlowField::draw(){
    
    float scalex = (float)externalWidth / (float)fieldWidth;
    float scaley = (float)externalHeight / (float)fieldHeight;
    
    for (int i = 0; i < fieldWidth; i++){
        for (int j = 0; j < fieldHeight; j++){
            int pos = j * fieldWidth + i;
            
            float px = 	i * scalex;
            float py = 	j * scaley;
            float px2 = px + field[pos].x * 5;
            float py2 = py + field[pos].y * 5;
            
            ofDrawLine(px,py, px2, py2);
            
            ofVec2f line;
            line.set(px2-px, py2-py);
            float length = line.length();
            line.normalize();
            line.rotate(90);
            ofDrawLine(px - line.x*length*0.2, py - line.y*length*0.2, px + line.x*length*0.2, py + line.y*length*0.2);
        }
    }
}

//------------------------------------------------------------
ofVec2f FlowField::getForceFromPos(float xpos, float ypos){
    
    ofVec2f frc;
    frc.set(0,0);
    
    float xPct = xpos / (float)externalWidth;
    float yPct = ypos / (float)externalHeight;
    
    if ((xPct < 0 || xPct > 1) || (yPct < 0 || yPct > 1)){
        return frc;
    }
    
    int fieldPosX = (int)(xPct * fieldWidth);
    int fieldPosY = (int)(yPct * fieldHeight);
    
    fieldPosX = MAX(0, MIN(fieldPosX, fieldWidth-1));
    fieldPosY = MAX(0, MIN(fieldPosY, fieldHeight-1));
    
    int pos = fieldPosY * fieldWidth + fieldPosX;
    
    frc.set(field[pos].x * 0.1, field[pos].y * 0.1 );
    return frc;
}


//------------------------------------------------------------
void FlowField::addClockwiseCircle(float x, float y, float radius, float strength){
    
    float pctx = x / (float)externalWidth;
    float pcty = y / (float)externalHeight;
    float radiusPct = radius / (float)externalWidth;
    
    
    int fieldPosX = (int)(pctx * (float)fieldWidth);
    int fieldPosY = (int)(pcty * (float)fieldHeight);
    float fieldRadius = (float)(radiusPct * fieldWidth);
    
    int startx = MAX(fieldPosX - fieldRadius, 0);
    int starty = MAX(fieldPosY - fieldRadius, 0);
    int endx = MIN(fieldPosX + fieldRadius, fieldWidth);
    int endy = MIN(fieldPosY + fieldRadius, fieldHeight);
    
    
    for (int i = startx; i < endx; i++){
        for (int j = starty; j < endy; j++){
            
            int pos = j * fieldWidth + i;
            float distance = (float)sqrt((fieldPosX-i)*(fieldPosX-i) +
                                         (fieldPosY-j)*(fieldPosY-j));
            
            if (distance < 0.0001) distance = 0.0001;
            
            if (distance < fieldRadius){
                
                float pct = 1.0f - (distance / fieldRadius);
                
                float strongness = strength * pct;
                float unit_px = ( fieldPosX - i) / distance;
                float unit_py = ( fieldPosY - j) / distance;
                field[pos].x += unit_py * strongness;
                field[pos].y -= unit_px * strongness;
            }
        }
    }
}

