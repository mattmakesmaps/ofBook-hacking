#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
	ofColor(255);

	const auto origin = ofPoint(0, 50);
	const auto stepSize = 10;
	const auto numVerts = 100;

	std::vector<glm::vec3> points{ origin };

	while (points.size() < numVerts) {
		points.push_back(ofPoint(stepSize * points.size(), 50));
	}

	auto polyline = ofPolyline(points);

	auto verts = polyline.getVertices();
	polyline.draw();

	// Draw the normals

	float normalLength = 50;
	for (int p = 0; p < 100; p += 10) {
		ofVec3f point = polyline.getPointAtPercent(p / 100.0);
		/*
		In this context, index is a float that corresponds to
		X.YY where X is the largest whole vertex a percentage of a line contains
		and YY is the percent between the vertex X and X+1.

		e.g. 2.75 == the position 75% the distance between vertex 2 and 3
		*/
		float floatIndex = polyline.getIndexAtPercent(p / 100.0);

		std::cout << floatIndex << std::endl;

		ofVec3f normal = polyline.getNormalAtIndexInterpolated(floatIndex) * normalLength;
		ofDrawLine(point - normal / 2, point + normal / 2);
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
