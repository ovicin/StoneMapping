#pragma once

#include "ofMain.h"
#include "ofxMtlMapping2D.h"
#include "ofxMacamPs3Eye.h"
#include "ofxSlitScan.h"



class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	
private:
    ofxMtlMapping2D* _mapping;
    ofxMacamPs3Eye ps3eye;
    ofImage img, colorImg, gradient, mask1, mask2, mask3, mask4, mask5, mask6;
	ofxSlitScan warp;
	
    bool bNewFrame;
    int capacity;
};
