#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	m_square.setup(1000);
}

//--------------------------------------------------------------
void ofApp::update() {
	m_square.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofColor centerColor = ofColor(200, 200, 200);
	ofColor edgeColor = ofColor(255, 255, 255);
	ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

	easyCam.begin();
	ofPushMatrix();
	ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
	m_square.draw();
	ofPopMatrix();
	easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key)
	{
	case 'q':
		m_square.displacementScale = m_square.displacementScale + 1;
		break;
	case 'a':
		m_square.displacementScale = m_square.displacementScale - 1;
		break;
	case 'z':
		m_square.displacementScale = 0.0;
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