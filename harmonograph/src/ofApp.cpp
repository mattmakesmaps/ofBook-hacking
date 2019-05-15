#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(0);
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);

	harmonograph h1 = harmonograph();
	harmonograph h2 = harmonograph();

	h1.setup(ofColor::red);
	h2.setup(ofColor::cadetBlue);

	harmonographs.push_back(h1);
	harmonographs.push_back(h2);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto & h : harmonographs)
	{
		h.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofTranslate((ofGetWidth() / 2),
		(ofGetHeight() / 2));

	for (auto & h : harmonographs)
	{
		h.draw();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
