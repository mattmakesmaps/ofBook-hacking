#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mesh.setMode(OF_PRIMITIVE_LINES);
	mesh.enableColors();
	mesh.enableIndices();

	glm::vec3 top(100.0, 50.0, 0.0);
	glm::vec3 left(50.0, 150.0, 0.0);
	glm::vec3 bottom(150.0, 150.0, 0.0);

	std::vector<glm::vec3> points = { top, left, bottom };
	std::vector<ofDefaultColorType> colors = { ofColor::red, ofColor::seaGreen, ofColor::lightGoldenRodYellow };
	mesh.addColors(colors);

	mesh.addVertices(points);

	mesh.addIndex(0);
	mesh.addIndex(1);
	mesh.addIndex(1);
	mesh.addIndex(2);
	mesh.addIndex(2);
	mesh.addIndex(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
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
