#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    bg_color = 255;
    
    ofSetCircleResolution(100);
    
    x1 = 100;
    y1 = 100;
    xx1 = 10;
    yy1 = 6;
    
    x2 = 350;
    y2 = 350;
    xx2 = 4;
    yy2 = 3;
    
    
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    x1 = x1+xx1;
    y1 = y1+yy1;
    if(y1 < 100 ||y1 > ofGetHeight()-100){
        yy1 *= -1;
    }
    if(x1 < 100 ||x1 > ofGetWidth()-100){
        xx1 *= -1;
    }
    
    
    x2 += xx2;
    y2 += yy2;
    if (y2<50 ||y2 > ofGetHeight()-50) {
        yy2 *= -1;
    }
    if (x2<50 ||x2 > ofGetWidth()-50){
        xx2 *= -1;
    }
    
    double dist = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
    if(dist < 150){
        xx1*=-1;
        xx2*=-1;
        yy1*=-1;
        yy2*=-1;
    }
    
    if (bg_color<255){
        bg_color += 5;
    } else if (bg_color>255){
        bg_color -= 5;
    }
    
    cout << bg_color << endl;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(bg_color); //  ofBackground(255, 255, 255);
    
    int i;
    for (i = 0; i<8; i++) {
        ofSetColor(i*40, i*30, i*10, 255);
        ofLine(i*128, 0, i*128, 768);
    }
    for (i = 0; i<6; i++) {
        ofLine(0, i*128, 1024, i*128);
    }
    
    ofColor black = ofColor(0, 0, 0);
    ofSetColor(black);
    
    ofColor pink = ofColor(255,192,203);
    ofSetColor(pink);
    ofFill();
    ofCircle( x1, y1, 100);
    
    ofSetColor(255, 0, 0, 128);
    ofFill();
    ofCircle( x2, y2, 50);
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        xx1 *= 2;
        yy1 *= 2;
    }
    if(key == 'b') {
        xx1 /= 2;
        yy1 /= 2;
    }
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
    
    if(pow(x-x1, 2)+pow(y-y1, 2) <= 10000){
        xx1 *= -1;
        yy1 *= -1;
        
        bg_color = 0;
    }

    
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
