#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	for (int i = 0; i < 9; ++i)
	{
		MKSquare tempSquare;
		tempSquare.setup(250);
		m_squares.push_back(tempSquare);
	}

	auto squares_per_row = 3;
	auto x_start = 100;
	auto y_start = 100;

	// Attempt to translate glm::vec3s directly.
	for (int s = 0; s < m_squares.size(); ++s)
	{

		int numVerts = m_squares[s].mesh.getNumVertices();
		for (int i = 0; i < numVerts; i++) {
			glm::vec3 vert = m_squares[s].mesh.getVertex(i);
			vert.x += (x_start);
			vert.y += (y_start);
			//vert.z += ();
			m_squares[s].mesh.setVertex(i, vert);
		}

		if ((s + 1) % squares_per_row == 0)
		{
			y_start += 350;
			x_start = 100;
		}
		else
		{
			x_start += 350;
		}
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

	for (int s = 0; s < m_squares.size(); ++s)
	{
		m_squares[s].draw();
	}

	vec2 mouse(mouseX, mouseY);
	auto x_str = std::to_string(mouseX);
	auto y_str = std::to_string(mouseY);
	vec2 offset(10, -10);
	ofDrawBitmapStringHighlight(x_str + " " + y_str, mouse + offset);
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
			square.displacementScale = square.displacementScale + 4;
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
