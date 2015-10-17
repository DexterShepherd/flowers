//
//  Particle.h
//  Flowers
//
//  Created by Dexter Shepherd on 3/11/15.
//
//

#ifndef Flowers_Particle_h
#define Flowers_Particle_h

#include "ofMain.h"

class Particle{
private:
    int whichDest;
    int numDests;
    float radius;
    float randomBound;
    vector<ofVec2f> dest;
    ofVec2f center;
    ofVec2f origin;
    ofVec2f location;
    ofVec2f reppeller;
    ofVec2f velocity;
    ofVec2f accelleration;
    ofVec2f force;
public:
    Particle(ofVec2f loc, float r, ofVec2f c, int nd, float rb);
    void setup();
    void update();
    void display();
    void updateDest(ofVec2f newCent);
    ofVec2f getLoc(){return location;};
    ofVec2f getAcc(){return accelleration;};
    ofVec2f getVel(){return velocity;};
    void setLoc(ofVec2f loc){location = loc;};
    void setAcc(ofVec2f acc){accelleration = acc;};
    void setVel(ofVec2f vel){velocity = vel;};
};
#endif
