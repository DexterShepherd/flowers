#include "ofApp.h"
#include "Particle.h"
#include "System.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false); //needed for motion blur effect
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();
    numParticles = 20000;
    numSystems = 1; //this whole systems array thing is kinda weird now that there is only one system on screen
    origins.assign(numSystems, 0);
    origins[0] = 5;
    ofVec2f tempLoc;
    float xSize = ofGetWidth()/3;
    float xOffset = xSize/2;
    tempLoc.set(ofGetWidth()/2, (ofGetHeight()/2));
    //number of particles, origin point of system, center of circle, radius of circle, number of points on circle
    system = new System(numParticles, tempLoc, tempLoc, ofGetWidth()/8, 3);
    
    opac = 0.0; //background stuff
    theta = 0.0;
    inc = 0.1;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    opac = ofMap(ofNoise(theta), 0, 1, 0, 30);
    system->update();
    theta += inc;
    if(theta > 100){theta = 0;};
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0, opac);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    system->display();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouse.set(ofGetMouseX(), ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //setup();
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
