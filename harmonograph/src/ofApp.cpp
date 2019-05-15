#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(0);
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	// See: https://stackoverflow.com/questions/686353/random-float-number-generation
	// See: http://www.walkingrandomly.com/?p=151
	// See: https://fronkonstin.com/tag/harmonograph/

	auto t = ofGetElapsedTimef();

	auto posX = exp(-d1 * t)*sin(t*f1 + p1) + exp(-d2 * t)*sin(t*f2 + p2);
	auto posY = exp(-d3 * t)*sin(t*f3 + p3) + exp(-d4 * t)*sin(t*f4 + p4);

	ofPoint tempP = ofPoint(posX * 400, posY * 400);
	points.push_back(tempP);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::aqua);
	ofNoFill(); 

	ofTranslate((ofGetWidth() / 2),
		(ofGetHeight() / 2));

	auto clipping_Vert = 300;

	if (points.size() >= clipping_Vert)
	{
		ofBeginShape();
		for (int i = clipping_Vert; i < points.size(); i++) {
			ofVertex(points[i].x, points[i].y);
		}
		ofEndShape();
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

float ofApp::calcX(float t)
{
	return 0.0f;
}

float ofApp::calcy(float t)
{
	return 0.0f;
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
