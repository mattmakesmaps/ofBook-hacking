#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	m_mesh.setMode(OF_PRIMITIVE_LINES);
	m_mesh.enableIndices();
	m_mesh.enableColors();

	auto width = ofGetWidth();
	auto height = ofGetHeight();

	int numColumns = 10;
	int numRows = 40;

	vector<glm::vec3> verts;
	vector<ofDefaultColorType> colors;

	for (int c = 0; c < numColumns; ++c) {
		for (int r = 0; r < numRows; ++r) {
			verts.push_back(glm::vec3(
				(c * (height / numColumns)),
				(r *(width / numRows)),
				0.0
			));
			colors.push_back(ofColor(c, r, 255));
		}
	}

	m_mesh.addColors(colors);
	m_mesh.addVertices(verts);

	float connectionDistance = width/numColumns;
	int numVerts = m_mesh.getNumVertices();
	for (int a = 0; a < numVerts; ++a) {
		ofVec3f verta = m_mesh.getVertex(a);
		for (int b = a + 1; b < numVerts; ++b) {
			ofVec3f vertb = m_mesh.getVertex(b);
			float distance = verta.distance(vertb);
			if (distance <= connectionDistance) {
				m_mesh.addIndex(a);
				m_mesh.addIndex(b);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	m_mesh.draw();
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
