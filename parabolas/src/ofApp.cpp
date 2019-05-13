#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void drawParabola() {

}

void ofApp::draw() {

	const auto maxLength = 1000;
	const auto origin = 0;
	const auto stepSize = maxLength / numSegments;

	ofBackground(0);
	ofSetColor(ofColor::aqua, 10);

	ofSetRectMode(OF_RECTMODE_CENTER);
	// Center viz to window.
	ofTranslate((ofGetWidth() / 2) - (maxLength / 2),
		(ofGetHeight() / 2) - (maxLength / 2));
	ofRotateZ(rotation);

	for (auto i = 0; i < numSegments; i++) {
		auto factor = stepSize * i + origin;
		auto factor2 = stepSize * (i + 1) + origin;
		std::vector<glm::vec3> pointVec = { ofVec3f(origin, factor), ofVec3f(factor2, maxLength + origin) };
		lines.push_back(ofPolyline(pointVec));
	}

	for (auto & l : lines)
	{
		l.draw();
		auto verts = l.getVertices();
		for (auto & v : verts)
		{
			ofDrawCircle(v, 5);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'a')
		rotation += 10;
	if (key == 'z')
		rotation -= 10;
	if (rotation >= 360)
		rotation = 0;
	if (rotation < 0)
		rotation = 360;

	if (key == 's')
		numSegments += 10;
	if (key == 'x')
		numSegments -= 10;
	if (numSegments <= 0)
		numSegments = 10;
	if (key == 'q')
		lines.clear();
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
