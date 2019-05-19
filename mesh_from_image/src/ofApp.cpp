#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	image.load("stars.png");

	mesh.setMode(OF_PRIMITIVE_POINTS);
	mesh.enableColors();

	float intensityThreshold = 150.0;
	int w = image.getWidth();
	int h = image.getWidth();

	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			ofColor c = image.getColor(x, y);
			float intensity = c.getLightness();
			if (intensity >= intensityThreshold) {
				ofVec3f pos(x, y, 0.0);
				mesh.addVertex(pos);
				mesh.addColor(c);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//image.draw(0, 0);
	ofBackground(0, 0, 255);
	mesh.draw();
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
