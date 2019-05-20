#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);

	image.load("calder.png");
	float intensityThreshold = 10.0; // Calder
	//image.load("central_library_01.png");
	//float intensityThreshold = 150.0;
	image.resize(270, 180); // shrink image to reduce processing
	mesh.setMode(OF_PRIMITIVE_LINES);
	mesh.enableIndices();
	mesh.enableColors();

	int w = image.getWidth();
	int h = image.getHeight();
	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			ofColor c = image.getColor(x, y);
			float intensity = c.getLightness();
			if (intensity >= intensityThreshold) {
				float saturation = c.getSaturation();
				float z = ofMap(saturation, 0, 255, -100, 100);
				glm::vec3 pos(x*4, y*4, z);
				mesh.addVertex(pos);
				mesh.addColor(c);

				offsets.push_back(glm::vec3(
					ofRandom(0, 100000),
					ofRandom(0, 100000),
					ofRandom(0, 100000)));
			}
		}
	}

	float connectionDistance = 15;
	int numVerts = mesh.getNumVertices();
	for (int a = 0; a < numVerts; ++a) {
		ofVec3f verta = mesh.getVertex(a);
		for (int b = a + 1; b < numVerts; ++b) {
			ofVec3f vertb = mesh.getVertex(b);
			float distance = verta.distance(vertb);
			if (distance <= connectionDistance) {
				mesh.addIndex(a);
				mesh.addIndex(b);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	// all of this has to do with noise
	/*
	int numVerts = mesh.getNumVertices();
	for (int i = 0; i < numVerts; i++) {
		glm::vec3 vert = mesh.getVertex(i);

		float time = ofGetElapsedTimef();
		float timeScale = 5.0;
		float displacementScale = 0.75;
		glm::vec3 timeOffsets = offsets[i];

		vert.x += (ofSignedNoise(time*timeScale + timeOffsets.x)) * displacementScale;
		vert.y += (ofSignedNoise(time*timeScale + timeOffsets.y)) * displacementScale;
		vert.z += (ofSignedNoise(time*timeScale + timeOffsets.z)) * displacementScale;
		mesh.setVertex(i, vert);
	}
	*/
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofColor centerColor = ofColor(85, 78, 68);
	ofColor edgeColor = ofColor(0,0,0);
	ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

	easyCam.begin();
		ofPushMatrix();
			ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
			mesh.draw();
		ofPopMatrix();
	easyCam.end();
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
