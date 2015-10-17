//
//  System.h
//  Flowers
//
//  Created by Dexter Shepherd on 3/12/15.
//
//

#ifndef __Flowers__System__
#define __Flowers__System__

#include <stdio.h>
#include "ofMain.h"
#include "Particle.h"

class System{
private:
    float life;
    int numParticles;
    ofVec2f origin;
    ofVec2f center;
    float radius;
    vector<Particle> particle;
    int numDests;
public:
    System(int np, ofVec2f o, ofVec2f c, float r, int nd);
    void update();
    void display();
    void setCenter(ofVec2f cen);
    void restart();
    ofVec2f getCenter(){return center;};
    
};

#endif /* defined(__Flowers__System__) */
