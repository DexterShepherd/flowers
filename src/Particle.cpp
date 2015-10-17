//
//  Particle.cpp
//  Flowers
//
//  Created by Dexter Shepherd on 3/11/15.
//
//

#include "Particle.h"
Particle::Particle(ofVec2f loc, float r, ofVec2f c, int nd, float rb){
    location = loc;
    origin = loc;
    numDests = 100;
    center = c;
    radius = r;
    numDests = nd;
    dest.assign(numDests, ofVec2f(0,0));
    randomBound = rb;
    
}
void Particle::setup(){
    velocity.set(ofRandom((randomBound)*-1, randomBound), ofRandom((randomBound)*-1, randomBound));
    float angle = 0;
    for(int i = 0; i < numDests; i++){
        angle = ofMap(i, 0, numDests, 0, TWO_PI);
        float x = sin(angle)*radius+center.x;
        float y = cos(angle)*radius+center.y;
        dest[i].set(x,y);
    }
    whichDest = ofRandom(numDests);
    
}

void Particle::update(){
    accelleration = dest[whichDest]-location;
    accelleration.normalize();
    accelleration *= 0.2;
    velocity = velocity+accelleration;
    velocity.limit(7);
    if(ofRandom(100000)> 99998){
        velocity.set(ofRandom(-1, 1), ofRandom(-1, 1));
    
    }
    location = location+velocity;
    
}

void Particle::display(){
    ofSetColor(255);
    ofFill();
    ofRect(location.x, location.y, 1, 1);
}

void Particle::updateDest(ofVec2f newCent){
    float angle = 0;
    center = newCent;
    for(int i = 0; i < numDests; i++){
        angle = ofMap(i, 0, numDests, 0, TWO_PI);
        float x = sin(angle)*radius+center.x;
        float y = cos(angle)*radius+center.y;
        dest[i].set(x,y);
    }
}