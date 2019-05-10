#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetWindowShape(1024, 768);

	ofSetFrameRate(60);

	ofSetBackgroundAuto(false);

	ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {

		const auto numTriangles = 10;
		const auto minOffset = 5;
		const auto maxOffset = 70;
		const auto alpha = 150;

		for (int t = 0; t < numTriangles; ++t) {
			auto offsetDistance = ofRandom(minOffset, maxOffset);

			ofVec2f lastMousePos(ofGetPreviousMouseX(), ofGetPreviousMouseY());
			ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

			vector<ofVec2f> myTriangle = { ofVec2f(0, 6.25),ofVec2f(25, 0),ofVec2f(0, -6.25) };

			// If the mouse has moved far, decrease size of triangle.
			// If the mouse has moved little, increase triangle size.
			if (mousePos.distance(lastMousePos) < 10)
			{
				multiplier.x = multiplier.x * 1.001;
				multiplier.y = multiplier.y * 1.001;
			}
			else {
				multiplier.x = multiplier.x * 0.995; // Note we're decreasing at a faster rate
				multiplier.y = multiplier.y * 0.995;
			}

			for (auto& p : myTriangle) {
				p = p * multiplier;
			}

			// Rotate the triangle
			auto rotation = ofRandom(360);
			// Offset Calculation
			ofVec2f triangleOffset(offsetDistance, 0.0);
			triangleOffset.rotate(rotation);

			for (auto& point : myTriangle) {
				point.rotate(rotation); // Rotate the triangle
				point += mousePos + triangleOffset; // translate position to mouse+offset 
			};

			ofColor aqua(0, 252, 255, alpha);
			ofColor purple(198, 0, 205, alpha);
			ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));

			ofSetColor(inbetween);

			// Can't pass in a vector<ofVec2f> so specify each member.
			ofDrawTriangle(myTriangle[0], myTriangle[1], myTriangle[2]);
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
