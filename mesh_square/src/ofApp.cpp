#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	for (int i = 0; i < 9; ++i)
	{
		MKSquare tempSquare;
		tempSquare.setup(250);
		m_squares.push_back(tempSquare);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (auto& square : m_squares)
	{
		square.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofColor centerColor = ofColor(200, 200, 200);
	ofColor edgeColor = ofColor(255, 255, 255);
	ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

	// Draw a 3 by n grid of squares.
	easyCam.begin();
	int squares_per_row = 3;
	ofPushMatrix();
		for (int s = 0; s < m_squares.size(); ++s)
		{
			m_squares[s].draw();
			if ((s + 1) % squares_per_row == 0)
			{
				ofPopMatrix();
					ofTranslate(0.0, 250, 0.0);
				ofPushMatrix();
			}
			else
			{
				ofTranslate(250, 0.0, 0.0);
			}
		}
	ofPopMatrix();
	easyCam.end();

	// The above maps to the following.
	/*
	ofPushMatrix();
		m_squares[0].draw();
		ofTranslate(250, 0.0, 0.0);
		m_squares[1].draw();
		ofTranslate(250, 0.0, 0.0);
		m_squares[2].draw();
	ofPopMatrix();
		ofTranslate(0.0, 250, 0.0);
	ofPushMatrix();
		m_squares[3].draw();
		ofTranslate(250, 0.0, 0.0);
		m_squares[4].draw();
		ofTranslate(250, 0.0, 0.0);
		m_squares[5].draw();
	ofPopMatrix();
		ofTranslate(0.0, 250, 0.0);
	ofPushMatrix();
		m_squares[6].draw();
		ofTranslate(250, 0.0, 0.0);
		m_squares[7].draw();
		ofTranslate(250, 0.0, 0.0);
		m_squares[8].draw();
	ofPopMatrix();
	*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key)
	{
	case 'q':
		for (auto& square : m_squares)
		{
			square.displacementScale = square.displacementScale + 1;
		}
		break;
	case 'a':
		for (auto& square : m_squares)
		{
			square.displacementScale = square.displacementScale - 1;
		}
		break;
	case 'z':
		for (auto& square : m_squares)
		{
			square.displacementScale = 0;
		}
		break;
	}
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	for (auto& square : m_squares)
	{
		if (square.pip_wn1(vec3(x, y, 0.0)))
		{
			square.displacementScale = square.displacementScale + 1;
		}
		else
		{
			square.displacementScale = 0;
		}
	}
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
