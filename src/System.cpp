//
//  System.cpp
//  Flowers
//
//  Created by Dexter Shepherd on 3/12/15.
//
//

#include "System.h"
#include "Particle.h"
System::System(int np, ofVec2f o, float r, ofVec2f c, int nd){
    origin  = o;
    numParticles = np;
    radius = r;
    center = c;
    numDests = nd;
    particle.assign(numParticles, Particle(origin, radius, center, numDests, 50));
    for(int i = 0; i < particle.size(); i++){
        particle[i].setup();
    }
}
void System::update(){
    for(int i = 0; i < particle.size(); i++){
        particle[i].update();
    }
}
void System::display(){
    for(int i = 0; i < particle.size(); i++){
        particle[i].display();
    }
}
void System::setCenter(ofVec2f cen){
    center = cen;
    for(int i = 0; i < particle.size(); i++){
        particle[i].updateDest(center);
    }
}

void System::restart(){
    particle.assign(numParticles, Particle(origin, radius, center, numDests, ofRandom(0, 50)));
    for(int i = 0; i < particle.size(); i++){
        particle[i].setup();
    }
}
