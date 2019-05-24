#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	m_mesh.setup(20, 20, ofColor::black);
	for (int i = 0; i < m_mesh.mesh.getNumVertices(); ++i) {
		offsets.push_back(glm::vec3(
			ofRandom(0, 10000),
			ofRandom(0, 10000),
			ofRandom(0, 10000)));
	}

	displacementScale = 0.75;
}

//--------------------------------------------------------------
void ofApp::update(){
	// Jitter Example from ofBook
	int numVerts = m_mesh.mesh.getNumVertices();
	for (int i = 0; i < numVerts; i++) {
		glm::vec3 vert = m_mesh.mesh.getVertex(i);
		float time = ofGetElapsedTimef();
		float timeScale = 5.0;
		glm::vec3 timeOffsets = offsets[i];
		vert.x += (ofSignedNoise(time*timeScale + timeOffsets.x)) * displacementScale;
		vert.y += (ofSignedNoise(time*timeScale + timeOffsets.y)) * displacementScale;
		vert.z += (ofSignedNoise(time*timeScale + timeOffsets.z)) * displacementScale;
		m_mesh.mesh.setVertex(i, vert);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofColor centerColor = ofColor(200,200,200);
	ofColor edgeColor = ofColor(255,255,255);
	ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

	easyCam.begin();
		ofPushMatrix();
			ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
			m_mesh.draw();
		ofPopMatrix();
	easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case 'q':
		displacementScale = displacementScale + 1;
		break;
	case 'a':
		displacementScale = displacementScale - 1;
		break;
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
