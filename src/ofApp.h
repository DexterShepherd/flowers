#pragma once


#include "ofMain.h"
#include "System.h"
#include "Particle.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    int width, height;
    ofVec2f mouse;

private:
    int numParticles;
    int numSystems;
    vector<int> origins;
    System* system;
    float opac;
    float inc;
    float theta;
    int second;
    int min;
    int lastMin;
};
