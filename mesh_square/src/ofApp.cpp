#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	auto length = 350;

	for (int i = 0; i < 9; ++i)
	{
		MKSquare tempSquare;
		tempSquare.setup(length);
		m_squares.push_back(tempSquare);
	}

	auto squares_per_row = 3;
	auto x_start = 100;
	auto y_start = 100;

	// Configure point origin.
	circle_origin.x = 750;
	circle_origin.y = 750;
	circle_stopped = true;

	/*
	ofTranslate doesn't actually alter the vertexes of the shapes themselves,
	therefore the point-in-polygon test doesn't reflect the actual screen
	coordinates.
	
	Attempt to translate verticies of each square's mesh directly.
	*/
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
			y_start += length + 100;
			x_start = 100;
		}
		else
		{
			x_start += length + 100;
		}
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	// BEGIN POINT UPDATE
	// Example Lissajus Curves:
	// https://github.com/openframeworks/ofBook/blob/master/chapters/animation/code/13_sinExample_circlePlusPath_lissajus/src/ofApp.cpp#L11
	if (!circle_stopped)
	{
		travelling_circle = circle_origin;
		float angle = ofGetElapsedTimef()*3.5;
		float radius = 450;
		travelling_circle.x = travelling_circle.x + radius * cos(angle * 0.7);
		travelling_circle.y = travelling_circle.y + radius * -sin(angle * 0.9);
	}
	// END POINT UPDATE

	for (auto& square : m_squares)
	{
		square.update();

		if (square.pip_wn1(vec3(travelling_circle.x, travelling_circle.y, 0.0)))
		{
			square.displacementScale = square.displacementScale + 5;
		}
		else
		{
			square.displacementScale = 0;
		}
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


	ofSetColor(255, 0, 127);
	ofFill();
	ofDrawCircle(travelling_circle.x, travelling_circle.y, 50);
	// END POINT DRAWING

	// Draw text box around mouse with current mouse position.
	// Found from: https://github.com/openframeworks/openFrameworks/blob/master/examples/3d/pointPickerExample/src/ofApp.cpp#L54
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
	case 'x':
		if (circle_stopped)
			circle_stopped = false;
		else
			circle_stopped = true;
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
