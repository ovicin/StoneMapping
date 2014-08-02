#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFrameRate(30);
    ofBackground(50);
    

  
    
    // ----
    _mapping = new ofxMtlMapping2D();
    _mapping->init(ofGetWidth(), ofGetHeight(), "mapping/xml/shapes.xml", "mapping/controls/mapping.xml");
    
    ps3eye.initGrabber(320, 240);
    ps3eye.setAutoGainAndShutter(true);

    img.loadImage("mask 001.png");
    img.resize(320, 240);
    
    mask1.loadImage("mask 002.png");
    mask1.resize(320, 240);
    
    mask2.loadImage("mask 003.png");
    mask2.resize(320, 240);
    
    mask3.loadImage("mask 004.png");
    mask3.resize(320, 240);
    
    mask4.loadImage("mask 005.png");
    mask4.resize(320, 240);
    
    mask5.loadImage("mask 002.png");
    mask5.resize(320, 240);
    
    mask6.loadImage("mask 002.png");
    mask6.resize(320, 240);
    
    capacity = 50;
    
    //gradient = new ofImage();
    gradient.allocate(320, 240, OF_IMAGE_GRAYSCALE);
     colorImg.allocate(320, 240, OF_IMAGE_COLOR);
    gradient.loadImage("left_to_right.png");
    //gradient.draw(0,0);

   warp.setup(320, 240, capacity);
    
    warp.setDelayMap(gradient);


    
    
     warp.setBlending(true);
}

//--------------------------------------------------------------
void ofApp::update(){
   
    _mapping->update();
    ps3eye.update();
    
    bNewFrame = ps3eye.isFrameNew();
    
  if (bNewFrame){
    colorImg.setFromPixels(ps3eye.getPixels(), 320,240, OF_IMAGE_COLOR);
    
        warp.addImage(colorImg);}
}

//--------------------------------------------------------------
void ofApp::draw(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // ----
    _mapping->bind();
    
    // draw a test pattern
    _mapping->chessBoard();
    ofEnableAlphaBlending();
    
    warp.getOutputImage().draw(0, 0);
    
    //ps3eye.draw(0, 0);

    mask1.draw(0, 0);
   
    warp.getOutputImage().draw(0, 240);
    //ps3eye.draw(0, 240);
    mask2.draw(0, 240);

    warp.getOutputImage().draw(0, 480);
    //ps3eye.draw(0, 480);
    mask3.draw(0, 480);
    
    warp.getOutputImage().draw(320, 0);
    //ps3eye.draw(320, 0);
    mask4.draw(320, 0);
    
    warp.getOutputImage().draw(320, 240);
    //ps3eye.draw(320, 240);
    mask5.draw(320, 240);
    
    warp.getOutputImage().draw(320, 480);
    //ps3eye.draw(320, 480);
    img.draw(320, 480);

    ofDisableAlphaBlending();
    
    _mapping->unbind();
    
    
    //-------- mapping of the towers/shapes
    _mapping->draw();

    //_mapping->drawFbo();
    
    
    //    ofBeginShape();
    //    ofFill();
    //    ofSetColor(0, 255, 0);
    //    for (int i = 0; i < _mapping->getMaskShapes()[0]->size(); i++) {
    //        ofVertex(_mapping->getMaskShapes()[0]->getVertices()[i].x, _mapping->getMaskShapes()[0]->getVertices()[i].y);
    //    }
    //    ofEndShape(true);
    
    
    // Draw some instructions.
    /*
     ofSetColor(0);
     ofDrawBitmapString("'m' open the mapping controls.\n", 20, 20);
     */

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
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