#include "ofApp.h"
#include "Particle.h"
#include "System.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();
    numParticles = 20000;
    numSystems = 1;
    origins.assign(numSystems, 0);
    origins[0] = 5;
    ofVec2f tempLoc;
    systems = new System*[numSystems];
    float xSize = ofGetWidth()/3;
    float xOffset = xSize/2;
    tempLoc.set(ofGetWidth()/2, (ofGetHeight()/2));
    systems[0] = new System(numParticles, tempLoc, ofGetWidth()/8, tempLoc, origins[0]);
    
    opac = 0.0;
    theta = 0.0;
    inc = 0.1;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    opac = ofMap(ofNoise(theta), 0, 1, 0, 30);
    for(int i = 0; i < numSystems; i++){
        systems[i]->update();
    }
    theta += inc;
    if(theta > 100){theta = 0;};
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0, opac);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    for(int i = 0; i < numSystems; i++){
        systems[i]->display();
    }
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
